from random import randint

n = int(input("Amount of nodes: "))
# l = int(input("Min amount of edges (1 < e < #nodes): "))
# m = int(input("Max amount of edges (1 < e < #nodes): "))
res = list()
i = 0
while i < n:
	x = randint(1, 30)
	y = randint(1, 30)
	if x == 1 and y == 1:
		continue
	s = f"{i} {x} {y}"
	res.append(s)
	i += 1
edges = list()
i = 0
while i < 2*n:
	x = randint(0, n-1)
	y = randint(0, n-1)
	s = f"{x}-{y}"
	if s not in edges:
		edges.append(s)
		i += 1
i = 0
m = randint(1, int(n/3))
while i < m:
	y = randint(0, n-1)
	s = f"S-{y}"
	if s not in edges:
		edges.append(s)
		i += 1
i = 0
m = randint(1, int(n/3))
while i < m:
	y = randint(0, n-1)
	s = f"E-{y}"
	if s not in edges:
		edges.append(s)
		i += 1
print("#ANTS")
print(randint(1, 100))
print("##start")
print("S 1 1")
print("##end")
print("E 33 33")
for l in res:
	print(l)
for e in edges:
	print(e)
	