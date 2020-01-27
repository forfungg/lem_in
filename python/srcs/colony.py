from collections import deque

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
		self.graph = dict()
		i = 0
		while i < len(self.nodes):
			k = 0
			self.graph[self.nodes[i].name] = []
			while k < len(self.pathways):
				if self.nodes[i].name == self.pathways[k][0]:
					self.nodes[i].edge.append(self.pathways[k][1])
					self.graph[self.nodes[i].name].append(self.pathways[k][1])
				elif self.nodes[i].name == self.pathways[k][1]:
					self.nodes[i].edge.append(self.pathways[k][0])
					self.graph[self.nodes[i].name].append(self.pathways[k][0])
				k += 1
			i += 1
		print(self.graph)
		# self.first_path()
		# self.find_all_paths()
		self.find_shortest_bsf()

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
		def search_path(node, visited, c, best):
			visited.append(node.name)
			if not node.start:
				c += 1
			if c > best:
				return -1
			if node.end:
				if len(visited) < best:
					best = len(visited)
				all_paths.append(visited.copy())
				print(visited)
				visited.pop(-1)
				return c
			elif len(node.edge) == 0:
				visited.pop(-1)
				return -1
			for next in node.edge:
				if next not in visited:
					i = self.get_node_index(next)
					ret = search_path(self.nodes[i], visited, c, best)
					if ret != -1 and ret < best:
						best = ret
			visited.pop(-1)
			return best
		c = search_path(self.nodes[0], visited, 0, 9999999)
		return c, all_paths

	def first_path(self):
		def find_path(graph, start, end, path = []):
			path = path + [start]
			if start == end:
				return path
			if not start in graph.keys():
				return None
			for node in graph[start]:
				if node not in path:
					newpath = find_path(graph, node, end, path)
					if newpath: return newpath
			return None
		ret = find_path(self.graph, self.nodes[0].name, self.nodes[-1].name)
		print("First Paths")
		print(ret)
	
	def find_all_paths(self):
		# super unefficient for larger graphs
		def find_all(graph, start, end, path = []):
			path = path + [start]
			if start == end:
				return [path]
			if not start in graph.keys():
				return []
			all_paths = []
			for node in graph[start]:
				if node not in path:
					new_paths = find_all(graph, node, end, path)
					for new in new_paths:
						if not new in all_paths:
							all_paths.append(new)
			return all_paths
		ret = find_all(self.graph, self.nodes[0].name, self.nodes[-1].name)
		print("All Paths")
		i = 1
		for p in ret:
			print(f"{i}: {p}")
			i += 1
	
	def find_shortest_path(self):
		def find_shortest(graph, start, end, path = []):
			path = path + [start]
			if start == end:
				return path
			if not start in graph.keys():
				return None
			shortest = None
			for node in graph[start]:
				if node not in path:
					new = find_shortest(graph, node, end, path)
					if new:
						if not shortest or len(new) < len(shortest):
							shortest = new
			return shortest
		ret = find_shortest(self.graph, self.nodes[0].name, self.nodes[-1].name)
		print("Shortest Path")
		print(ret)
	
	def find_shortest_bsf(self):
		def find_shortest_path(graph, start, end):
			dist = {start: [start]}
			q = deque(start)
			print(q)
			while len(q):
				at = q.popleft()
				print(at)
				for next in graph[at]:
					if next not in dist:
						dist[next] = [dist[at], next]
						q.append(next)
			return dist.get(end)
		ret = find_shortest_path(self.graph, self.nodes[0].name, self.nodes[-1].name)
		print("Shortest Path BSF")
		print(ret)