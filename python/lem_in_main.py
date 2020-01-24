import tkinter as tk

class LemInGui:
	def __init__(self, root, colony):
		self.root = root
		self.ratio = 50
		self.root.geometry("1100x1100")
		self.colony = colony
		self.canva = tk.Canvas(self.root, width=1000, height=1000, bd=5, relief=tk.GROOVE, bg="black")
		self.canva.pack()
		self.draw_nodes()
		self.draw_edges()
	
	def draw_nodes(self):
		for n in self.colony.nodes:
			self.canva.create_rectangle(n.point[0] * self.ratio, n.point[1] * self.ratio, n.point[0] * self.ratio + 10, n.point[1] * self.ratio + 10, fill="green")
			self.canva.create_text(n.point[0] * self.ratio, n.point[1] * self.ratio - 10, text=n.name, fill="red")
		self.canva.update()
	
	def draw_edges(self):
		for n in self.colony.nodes:
			for e in n.edge:
				i = self.colony.get_node_index(e)
				x = self.colony.nodes[i].point[0]
				y = self.colony.nodes[i].point[1]
				self.canva.create_line(n.point[0] * self.ratio + 5, n.point[1] * self.ratio + 5, x * self.ratio + 5, y * self.ratio + 5, fill="green")
		self.canva.update()

def open_file():
	while 1:
		try:
			filename = input("Insert filename:\n")
			print("\n")
			f = open(filename, "r")
		except OSError:
			print("Couldn't open the file, try again")
		else:
			break
	res = f.read()
	f.close()
	return res
def read_node_def(text):
	elems=text.split()
	if len(elems) != 3:
		print("ERROR")
		exit()
	return elems

def read_edge_info(text):
	elems=text.split('-')
	if len(elems) != 2:
		print("Fucked up path")
		exit()
	return elems

def read_colony(colony_text):
	i = 0
	res = Colony()
	colony_object = colony_text.split("\n")
	while i < len(colony_object):
		if colony_object[i] == "##start":
			i += 1
			ret = read_node_def(colony_object[i])
			node = Node(ret[0], int(ret[1]), int(ret[2]))
			node.start = True
			res.nodes.insert(0, node)
		elif colony_object[i] == "##end":
			i += 1
			ret = read_node_def(colony_object[i])
			node = Node(ret[0], int(ret[1]), int(ret[2]))
			node.end = True
			res.nodes.append(node)
		elif colony_object[i][0] == '#':
			pass
		elif " " in colony_object[i]:
			ret = read_node_def(colony_object[i])
			node = Node(ret[0], int(ret[1]), int(ret[2]))
			if len(res.nodes) > 0 and res.nodes[-1].end:
				res.nodes.insert(-1, node)
			else:
				res.nodes.append(node)
		elif "-" in colony_object[i]:
			ret = read_edge_info(colony_object[i])
			res.pathways.append(ret);
		elif colony_object[i].isdigit():
			res.ants = int(colony_object[i])
		else:
			print(f"Some shit went wrong @reading the colony instructions.\nLine: \"{colony_object[i]}\"")
			exit()
		i += 1
	return res

class Node():
	def __init__(self, name, x, y):
		self.name = name
		self.edge = list()
		self.point = (x, y)
		self.start = False
		self.end = False
		self.empty = True
	
	def __str__(self):
		str = f"Node: {self.name}\nCoords: {self.point}\nEdges: {self.edge}\nEmpty: {self.empty}\nParam: "
		if self.start:
			str += "Start"
		elif self.end:
			str += "End"
		else:
			str += "Normal"
		return str + "\n"
	
class Colony():
	def __init__(self):
		self.nodes = list()
		self.pathways = list()
		self.size = 0
		self.ants = 0
	
	def __str__(self):
		str = f"Colony Lem_In\nAnts: {self.ants}\nPathways: {self.pathways}\n"
		for node in self.nodes:
			str += "\n" + node.__str__()
		return str
	
	def pars_pathways(self):
		i = 0
		while i < len(self.nodes):
			k = 0
			while k < len(self.pathways):
				if self.nodes[i].name == self.pathways[k][0]:
					self.nodes[i].edge.append(self.pathways[k][1])
					self.pathways.pop(k)
				elif self.nodes[i].name == self.pathways[k][1]:
					self.nodes[i].edge.append(self.pathways[k][0])
					self.pathways.pop(k)
				else:
					k += 1
			i += 1

	def get_node_index(self, name):
		i = 0
		while i < len(self.nodes):
			if self.nodes[i].name == name:
				break
			i += 1
		else:
			return -1
		return i

	def min_path(self):
		'''
		Returns minimum amount of steps to travers from start to end
		'''
		visited = list()
		
		def search_path(node, visited):
			c = 0
			if not node.start:
				c += 1
			if node.end:
				return c
			elif len(node.edge) == 0:
				return -1
			visited.append(node.name)
			print(visited)
			best = 9999999 #fix
			for next in node.edge:
				if next not in visited:
					i = self.get_node_index(next)
					ret = search_path(self.nodes[i], visited)
					if ret != -1 and ret < best:
						best = ret
			if best == 9999999:
				return -1
			visited.pop(-1)
			return c + best
		
		c = search_path(self.nodes[0], visited)
		return c

if __name__ == "__main__":
	ret = open_file()
	my_colony = read_colony(ret)
	my_colony.pars_pathways()
	print(my_colony)
	minpath = my_colony.min_path()
	print(f"Shortest path: {minpath}")
	root = tk.Tk()
	lemin = LemInGui(root, my_colony)
	root.mainloop()