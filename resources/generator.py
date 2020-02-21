from random import randint
from threading import Thread
from threading import Lock
from queue import Queue
from time import sleep

exitFlag = 0

class GenerateRand(Thread):
	def __init__(self, tid, q):
		Thread.__init__(self)
		self.tid = tid
		self.q = q

	def run(self):
		# print(f"Starting Thread-{self.tid}")
		process_data(self.tid, self.q)
		# print(f"Exiting Thread-{self.tid}")

def create_edges(amount, limit, edges):
	i = 0
	while i < amount:
		x = randint(0, limit-1)
		y = randint(0, limit-1)
		s = f"{x}-{y}"
		# sr = f"{y}-{x}"
		# if not s in edges and not sr in edges:
		edges.append(s)
		i += 1

def process_data(tid, q):
	while not exitFlag:
		qlock.acquire()
		if not workq.empty():
			data = q.get()
			qlock.release()
			# print(f"Thread-{tid} processing at {len(data[2])}")
			create_edges(data[0], data[1], data[2])
		else:
			qlock.release()
		# sleep(0.1)

# n = int(input("Amount of nodes: "))
n = 1024
# density = (2 * edge) / (vertices)(vertices-1)
# (d * n * (n -1)) / 2 = edges
# d = int(input("Desired density (%, 1-100): "))
d = 20
# filename = input("Filename?\n")
filename = "test_speed"
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
max_e = ((d / 100) * n * (n - 1)) / 2
max_e += 1
print (f"Starting to generate {max_e} edges")
qlock = Lock()
workq = Queue()
threads = list()
t_count = 8
for i in range(t_count):
	t = GenerateRand(i, workq)
	t.start()
	threads.append(t)
qlock.acquire()
i = 0
alle = list()
while i < max_e:
	new = list()
	alle.append(new)
	workq.put([128, n, new])
	i += 128
qlock.release()
while not workq.empty():
	pass
exitFlag = 1
for t in threads:
	t.join()

print("Done generating")
print(len(alle))

exit()

create_edges(max_e, n, edges)

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

	