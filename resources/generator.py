from random import randint
# from threading import Thread
# from queue import Queue

# class GenerateRand(Thread):
# 	def __init__(self, q, n):
# 		Thread.__init__(self)
# 		self.q = q
# 		self.n = n

# 	def run(self):
# 		data = self.q.get()
# 		while True:
# 			x = randint(0, self.n-1)
# 			y = randint(0, self.n-1)
# 			s = f"{x}-{y}"
# 			sr = f"{y}-{x}"
# 			if not s in data and not sr in data:
# 				data.append(s)
# 				break
# 		return data
			

n = int(input("Amount of nodes: "))
# density = (2 * edge) / (vertices)(vertices-1)
# (d * n * (n -1)) / 2 = edges
d = int(input("Desired density (%, 1-100): "))
filename = input("Filename?\n")
# l = int(input("Min amount of edges (1 < e < #nodes): "))
# m = int(input("Max amount of edges (1 < e < #nodes): "))
# queue = Queue()

res = list()
i = 0
while i < n:
	x = randint(10, 490)
	y = randint(10, 490)
	if x == 1 and y == 1:
		continue
	s = f"{i} {x} {y}"
	res.append(s)
	i += 1
edges = list()
i = 0
max_e = ((d / 100) * n * (n - 1)) / 2
while i < max_e + 1:
	x = randint(0, n-1)
	y = randint(0, n-1)
	s = f"{x}-{y}"
	sr = f"{y}-{x}"
	if not s in edges and not sr in edges:
		edges.append(s)
		i += 1
i = 0
m = randint(1, int(d/100 * n))
while i < m:
	y = randint(0, n-1)
	s = f"S-{y}"
	if s not in edges:
		edges.append(s)
	i += 1
i = 0
while i < m:
	y = randint(0, n-1)
	s = f"E-{y}"
	if s not in edges:
		edges.append(s)
		i += 1
with open(filename, "w+") as f:
	ant = randint(1, 100)
	f.write(f"#Given {n} nodes, {d}% density\n#ANTS\n{ant}\n##start\nS 6 6\n##end\nE 495 495\n")
	i = 0
	for l in res:
		f.write(f"{l}\n")
	while i < len(edges) - 1:
		f.write(f"{edges[i]}\n")
		i += 1
	f.write(f"{edges[i]}")

	