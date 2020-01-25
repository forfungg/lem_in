from srcs.colony import Colony, Node

def open_file(filename):
	try:
		f = open(filename, "r")
	except OSError:
		print("Couldn't open the file, try again")
		exit()
	else:
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
			res.pathways.append(ret)
		elif colony_object[i].isdigit():
			res.ants = int(colony_object[i])
		else:
			print(f"Some shit went wrong @reading the colony instructions.\nLine: \"{colony_object[i]}\"")
			exit()
		i += 1
	return res
