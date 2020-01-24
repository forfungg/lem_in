from random import randint

n = int(input("Amount of nodes: "))
l = int(input("Min amount of edges (1 < e < #nodes): "))
m = int(input("Max amount of edges (1 < e < #nodes): "))
res = list()
for i in range(n):
	x = randint(0, 99)
	y = randint(0, 99)
	res.append(f"{i} {x} {y}")
	