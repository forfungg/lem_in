from collections import deque

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
class Ant:
	def __init__(self, name, position):
		self.name = name
		self.pos = position
		self.path = list()
		self.color = "#ffffff"
		self.size = 15
	
	def __str__(self):
		return f"{self.name}-{self.pos}"
	
	def add_path(self, path):
		self.path = path.copy()
	
	def move(self):
		if len(self.path) > 0:
			self.position = self.path.pop(0)

class Node():
	def __init__(self, name, x, y):
		self.name = name
		self.neighbors = list()
		self.point = (x, y)
		self.start = False
		self.end = False
		self.empty = True
		self.lvl = 2147483646
		self.visited = False
	
	def __str__(self):
		str = f"Node: {self.name}\nCoords: {self.point}\nNeighbors: {self.neighbors}\nEmpty: {self.empty}\nParam: "
		if self.start:
			str += "Start"
		elif self.end:
			str += "End"
		else:
			str += "Normal"
		str += f"\nLevel: {self.lvl}\nVisited: {self.visited}"
		return str + "\n"
	
	def add_neighbor(self, v):
		if v not in self.neighbors:
			self.neighbors.append(v)
			self.neighbors.sort()

class Colony():
	def __init__(self):
		self.nodes = dict()
		self.pathways = list()
		self.size = 0
		self.ants = 0
		self.ants_list = list()
		self.start = None
		self.end = None
		self.all_paths = list()
		self.unique_paths = list()
		self.ants_to_path = list()
	
	def __str__(self):
		str = f"Colony Lem_In\nAnts: {self.ants}\nPathways: {self.pathways}\n"
		for node in self.nodes:
			str += "\n" + self.nodes[node].__str__()
		return str
	
	def add_node(self, node):
		if isinstance(node, Node) and node.name not in self.nodes:
			self.nodes[node.name] = node
			return True
		else:
			return False
	
	def read_colony(self, colony_text):
		i = 0
		colony_object = colony_text.split("\n")
		while i < len(colony_object):
			if colony_object[i] == "##start":
				i += 1
				ret = read_node_def(colony_object[i])
				node = Node(ret[0], int(ret[1]), int(ret[2]))
				node.start = True
				if not self.add_node(node):
					print("Error adding node")
				self.start = node.name
			elif colony_object[i] == "##end":
				i += 1
				ret = read_node_def(colony_object[i])
				node = Node(ret[0], int(ret[1]), int(ret[2]))
				node.end = True
				if not self.add_node(node):
					print("Error adding node")
				self.end = node.name
			elif colony_object[i][0] == '#':
				pass
			elif " " in colony_object[i]:
				ret = read_node_def(colony_object[i])
				node = Node(ret[0], int(ret[1]), int(ret[2]))
				if not self.add_node(node):
					print("Error adding node")
			elif "-" in colony_object[i]:
				ret = read_edge_info(colony_object[i])
				self.pathways.append(ret)
			elif colony_object[i].isdigit():
				self.ants = int(colony_object[i])
			else:
				print(f"Some shit went wrong @reading the colony instructions.\nLine: \"{colony_object[i]}\"")
				exit()
			i += 1

	def pars_pathways(self):
		for edge in self.pathways:
			if edge[0] in self.nodes and edge[1] in self.nodes:
				self.nodes[edge[0]].add_neighbor(edge[1])
				self.nodes[edge[1]].add_neighbor(edge[0])
			else:
				print(f"Couldn't find either node: {edge}")

	def bfs(self, node):
		if not isinstance(node, Node):
			print("Trying BFS with no-node type")
			exit()
		q = deque()
		node.lvl = 0
		node.visited = True
		for n in node.neighbors:
			self.nodes[n].lvl = node.lvl + 1
			q.append(n)
		
		while len(q) > 0:
			u = q.popleft()
			node_u = self.nodes[u]
			node_u.visited = True

			for v in node_u.neighbors:
				node_v = self.nodes[v]
				if not node_v.visited:
					q.append(v)
					if node_v.lvl > node_u.lvl + 1:
						node_v.lvl = node_u.lvl + 1
	
	def reset_visit(self):
		for n in self.nodes:
			self.nodes[n].visited = False
	
	def shortest_path(self):
		self.reset_visit()
		q = [[self.nodes[self.start].name]]
		
		while q:
			path = q.pop(0)
			node = self.nodes[path[-1]]
			if not node.visited:
				for n in node.neighbors:
					new_path = list(path)
					new_path.append(n)
					q.append(new_path)
					if n == self.end:
						if new_path in self.all_paths:
							q.pop(-1)
						else:
							return new_path
			node.visited = True
		return None
	
	def search_usefulpaths(self):
		if len(self.nodes[self.start].neighbors) < len(self.nodes[self.end].neighbors):
			limit = len(self.nodes[self.start].neighbors)
		else:
			limit = len(self.nodes[self.end].neighbors)
		while len(self.unique_paths) < limit:
			new_path = self.shortest_path()
			if new_path == None:
				break
			self.all_paths.append(new_path)
			self.pars_unique()
		print(self.all_paths)
		return self.all_paths

	def pars_unique(self):
		self.unique_paths = self.all_paths.copy()
		def check_in(a, b):
			for p in a:
				if p in b:
					return True
			return False
		i = 0
		while i < len(self.unique_paths):
			a = self.unique_paths[i][1:-1]
			j = i + 1
			while j < len(self.unique_paths):
				b = self.unique_paths[j][1:-1]
				if check_in(a, b):
					self.unique_paths.pop(j)
					j = i + 1
					continue
				else:
					j += 1
			i += 1
		return self.unique_paths

	def distribute_ants(self):
		def get_filla(lst):
			tmp = lst.copy()
			pt = 0
			for p in tmp:
				pt += len(p)
			ro = len(tmp[-1]) * len(tmp)
			to_fill = ro - pt
			if to_fill > self.ants:
				tmp.pop(-1)
				return get_filla(tmp)
			else:
				return len(tmp)

		if len(self.unique_paths) == 0:
			self.ants_to_path = None
		elif len(self.unique_paths) == 1:
			self.ants_to_path = [self.ants]
		else:
			i = 0
			while i < len(self.unique_paths):
				self.ants_to_path.append(0)
				i += 1
			# get rectangle
			limit = get_filla(self.unique_paths)
			i = 0
			while i < limit - 1:
				self.ants_to_path[i] = len(self.unique_paths[limit - 1]) - len(self.unique_paths[i])
				i += 1
			current = self.ants - sum(self.ants_to_path)
			tbd = current - (current % limit)
			current -= tbd
			tbd = int(tbd / limit)
			i = 0
			while i < limit:
				self.ants_to_path[i] += tbd
				i += 1
			while current > 0:
				self.ants_to_path[current - 1] += 1
				current -= 1
		for i in range(len(self.unique_paths)):
			print(f"Ants {self.ants_to_path[i]} for path {self.unique_paths[i]}")
	
	def identify_ants(self):
		for i in range(1 , self.ants + 1):
			a = Ant(f"L{i}", self.start)
			self.ants_list.append(a)

	def assign_paths(self):
		tmp = self.ants_to_path.copy()
		a = 0
		while a < self.ants:
			i = 0
			while i < len(self.unique_paths):
				if tmp[i] > 0:
					self.ants_list[a].add_path(self.unique_paths[i])
					a += 1
					tmp[i] -= 1
				i += 1
		
	def create_turns(self):
		self.identify_ants()
		self.assign_paths()
		for a in self.ants_list:
			print(f"{a.name}: {a.path}")



if __name__ == "__main__":
	my_colony = Colony()
	with open("../../resources/lem_map_100", "r") as f:
		ret = f.read()
	my_colony.read_colony(ret)
	my_colony.pars_pathways()
	my_colony.bfs(my_colony.nodes[my_colony.start])
	print(my_colony)
	print(my_colony.shortest_path())