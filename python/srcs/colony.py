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
				return i
			i += 1
		print(f"Cannot find {name} in nodes")
		exit()
		

	def min_path(self):
		'''
		Returns minimum amount of steps to travers from start to end
		'''
		visited = list()
		all_paths = list()
		def search_path(node, visited):
			c = 0
			visited.append(node.name)
			if not node.start:
				c += 1
			if node.end:
				all_paths.append(visited.copy())
				visited.pop(-1)
				return c
			elif len(node.edge) == 0:
				visited.pop(-1)
				return -1
			best = 9999999 #fix
			for next in node.edge:
				if next not in visited:
					i = self.get_node_index(next)
					ret = search_path(self.nodes[i], visited)
					if ret != -1 and ret < best:
						best = ret
			if best == 9999999:
				visited.pop(-1)
				return -1
			visited.pop(-1)
			return c + best
		c = search_path(self.nodes[0], visited)
		return c, all_paths