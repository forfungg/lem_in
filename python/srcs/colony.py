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
		self.visible = True
	
	def __str__(self):
		return f"{self.name}-{self.pos}"
	
	def add_path(self, path):
		self.path = path.copy()
		self.path.pop(0)
	
	def move(self):
		if len(self.path) > 0:
			self.pos = self.path.pop(0)

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
		self.flow = 0
		self.capacity = 1
	
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
	
	def mark_start(self, ants):
		self.start = True
		self.flow = ants
		self.capacity = 2147483646
	
	def mark_end(self):
		self.end = True
		self.capacity = 2147483646

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

	def bfs_pathexists(self, start, end):
		self.reset_visit()
		q = list()
		q.append(start)
		while q:
			current = self.nodes[q.pop(0)]
			current.visited = True
			for n in current.neighbors:
				if n == end:
					return True
				if not self.nodes[n].visited and not self.nodes[n].flow:
					q.append(n)
		return False
	
	def reset_visit(self):
		for n in self.nodes:
			self.nodes[n].visited = False
	
	def shortest_path(self):
		self.reset_visit()
		q = [[self.nodes[self.start].name]]
		while q:
			print(f"Current queue: {q}")
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
	
	# def ford_fulkerson(self):
	# 	#find max potential flow
	# 	limit = self.find_limit()
	# 	print(limit)
	# 	flow = 0
	# 	best = None
	# 	path = self.bfs_pathexists(self.start, self.end)
	# 	if not path:
	# 		print("No path found between start and end")
	# 		return best
	# 	while flow < limit:
	# 		q = list()
	# 		solution = list(best)
	# 		self.mark_flows(solution)
	# 		q.append([self.start])
	# 		while q:
	# 			path = q.pop(0)
	# 			node = self.nodes[path[-1]]
	# 			if node.end:
	# 				solution.append(path)
	# 				break
	# 			if not node.flow:
	# 				for n in node.neighbors:
	# 					new = list(path)
	# 					new.append(n)
	# 					q.append(new)
	# 			elif node.flow and not node.name in path:
	# 				cta =
	# 				# find the node in the already existing solution
	# 				# search for alternative path from all previous nodes
	# 				# if path exists and new solution would be better than save as best
	# 				# else delete current and continue?
	# 				pass
	# 			node.flow = 1
	# 		# check the current solution
	# 		if best == None or self.solution_len(solution, self.ants) < self.solution_len(best, self.ants):
	# 			best = solution.copy()
	# 		if not q:
	# 			break
	# 		flow = len(best)
	# 	return best

	def mark_flows(self, paths):
		for node in self.nodes:
			if node.start or node.end:
				continue
			node.flow = 0
		for path in paths:
			for n in path:
				if n == self.start or n == self.end:
					continue
				else:
					self.nodes[n].flow = 1
	
	def solution_len(self, paths, ants):
		p_len = list()
		for path in paths:
			p_len.append(len(path))
		while ants:
			i = p_len.index(min(p_len))
			p_len[i] += 1
			ants -= 1
		return max(p_len)

	def find_limit(self):
		s = len(self.nodes[self.start].neighbors)
		e = len(self.nodes[self.end].neighbors)
		return min(s, e, self.ants)
	
	def set_start_end(self):
		self.nodes[self.start].mark_start(self.ants)
		self.nodes[self.end].mark_end()
	
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
	
	def get_ants_dict(self):
		ret_ants = list()
		for i in range(1 , self.ants + 1):
			ant = Ant(f"L{i}", self.start)
			ret_ants.append(ant)
		tmp = self.ants_to_path.copy()
		a = 0
		while a < self.ants:
			i = 0
			while i < len(self.unique_paths):
				if tmp[i] > 0:
					ret_ants[a].add_path(self.unique_paths[i])
					a += 1
					tmp[i] -= 1
				i += 1
		res = dict ()
		for a in ret_ants:
			res[a.name] = a
		return res
		
	def create_turns(self):
		self.identify_ants()
		self.assign_paths()
		def check_if_move():
			for a in self.ants_list:
				if len(a.path) > 0:
					return True
			return False
		self.turns = list()
		while check_if_move():
			turn = dict()
			for a in self.ants_list:
				if self.move_one_ant(a):
					turn[a.name] = a.pos
			self.turns.append(turn)
		print(self.turns)
		self.print_turns()
	
	def print_turns(self):
		s = ""
		for turn in self.turns:
			if s != "":
				s += "\n"
			for key in turn:
				s += f"{key}-{turn[key]} "
		print(s)

	def move_one_ant(self, ant):
		c_node = self.nodes[ant.pos]
		if c_node.end or len(ant.path) == 0:
			return False
		n_node = self.nodes[ant.path[0]]
		if n_node.empty or n_node.end:
			ant.move()
			c_node.empty = True
			n_node.empty = False
			return True
		else:
			return False

if __name__ == "__main__":
	my_colony = Colony()
	with open("../../resources/lem_map_4k_01", "r") as f:
		ret = f.read()
	my_colony.read_colony(ret)
	my_colony.pars_pathways()
	res = my_colony.bfs_pathexists(my_colony.start, my_colony.end)
	print(res)
	# my_colony.ford_fulkerson()