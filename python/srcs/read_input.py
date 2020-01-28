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