import tkinter as tk
import tkinter.filedialog
from random import randint
from srcs.colony import Colony
from sys import argv

class LemInGui:
	def __init__(self, root):
		self.root = root
		self.load_file_start()
		self.ratio = 2
		self.ed_on = tk.IntVar(value=1)
		self.pth_on = tk.IntVar(value=0)
		# self.root.geometry("1100x1100")
		self.init_tools()
		self.scrl_v = tk.Scrollbar(self.root)
		self.scrl_v.pack(side=tk.RIGHT, fill=tk.Y)
		self.scrl_h = tk.Scrollbar(self.root)
		self.scrl_h.pack(side=tk.BOTTOM, fill=tk.X)
		self.canva = tk.Canvas(self.root, width=1600, height=1600, bd=5, relief=tk.GROOVE, bg="black", yscrollcommand=self.scrl_v.set, xscrollcommand=self.scrl_h.set)
		self.canva.pack(side=tk.TOP)
		self.scrl_h.config(command=self.canva.xview)
		self.scrl_v.config(command=self.canva.yview)
		self.draw_nodes()
		self.draw_edges()
	
	def init_tools(self):
		self.toolbar = tk.Frame(self.root)
		self.tb1 = tk.Button(self.toolbar, text="Load Lem_In", command=self.load_file)
		self.tb1.pack(side=tk.LEFT, padx=2, pady=2)
		self.tb2 = tk.Button(self.toolbar, text="Redraw", command=self.reset_graph)
		self.tb2.pack(side=tk.LEFT, padx=2, pady=2)
		self.chb1 = tk.Checkbutton(self.toolbar, text="Edges", variable=self.ed_on, onvalue=1,  offvalue=0, command=self.reset_graph)
		self.chb1.pack(side=tk.LEFT, padx=2, pady=2)
		self.chb2 = tk.Checkbutton(self.toolbar, text="Paths", variable=self.pth_on, onvalue=1,  offvalue=0, command=self.reset_graph)
		self.chb2.pack(side=tk.LEFT, padx=2, pady=2)
		self.toolbar.pack(side = tk.TOP, fill = tk.X)

	def draw_nodes(self):
		for v in self.colony.nodes:
			n = self.colony.nodes[v]
			self.canva.create_rectangle(n.point[0] * self.ratio, n.point[1] * self.ratio, n.point[0] * self.ratio + 10, n.point[1] * self.ratio + 10, fill="green")
			self.canva.create_text(n.point[0] * self.ratio, n.point[1] * self.ratio - 10, text=n.name, fill="red")
		self.canva.update()
	
	def draw_edges(self):
		if self.ed_on.get():
			for v in self.colony.nodes:
				n = self.colony.nodes[v]
				if len(n.neighbors) == 0:
					continue
				else:
					j = 0
					while j < len(n.neighbors):
						i = n.neighbors[j]
						x = self.colony.nodes[i].point[0]
						y = self.colony.nodes[i].point[1]
						self.canva.create_line(n.point[0] * self.ratio + 5, n.point[1] * self.ratio + 5, x * self.ratio + 5, y * self.ratio + 5, fill="green")
						j += 1
			self.canva.update()
	
	def get_paths_color(self):
		default_set = ["#ff0000", "#0000ff", "#ff0066", "#00ffff", "#ffffff", "#993399", "#ffa31a", "#ffccff", "#ffff00"]
		self.paths_colorset = default_set.copy()
		if len(self.paths_colorset) < len(self.all_paths):
			i = len(self.paths_colorset)
			while i < len(self.all_paths):
				r = randint(10,255)
				g = randint(10,255)
				b = randint(10,255)
				color = "#%02x%02x%02x"%(r,g,b)
				if color not in self.paths_colorset:
					self.paths_colorset.append(color)
					i += 1
				else:
					continue
	
	def show_path_no(self, i):
		path = self.all_paths[i]
		color = self.paths_colorset[i]
		j = 0
		while j < len(path) - 1:
			n1 = self.colony.nodes[path[j]]
			x1 = n1.point[0]
			y1 = n1.point[1]
			n2 = self.colony.nodes[path[j + 1]]
			x2 = n2.point[0]
			y2 = n2.point[1]
			self.canva.create_rectangle(n1.point[0] * self.ratio, n1.point[1] * self.ratio, n1.point[0] * self.ratio + 10, n1.point[1] * self.ratio + 10, fill=color)
			self.canva.create_rectangle(n2.point[0] * self.ratio, n2.point[1] * self.ratio, n2.point[0] * self.ratio + 10, n2.point[1] * self.ratio + 10, fill=color)
			self.canva.create_line(x1 * self.ratio + 5, y1 * self.ratio + j + 1, x2 * self.ratio + 5, y2 * self.ratio + j, fill=color)
			self.canva.create_line(x1 * self.ratio + 5, y1 * self.ratio + j + 2, x2 * self.ratio + 5, y2 * self.ratio + j, fill=color)
			
			j += 1
		self.canva.update()
	
	def get_paths(self):
		self.all_paths = list()
		self.colony.search_usefulpaths()
		self.all_paths = self.colony.pars_unique()
		# self.all_paths.append(self.colony.shortest_path())
		self.shortest = len(self.all_paths[0])
		self.get_paths_color()
		self.path_on = list()
		i = 0
		while i < len(self.all_paths):
			self.path_on.append(False)
			i += 1
		print(self.shortest)
		print(self.all_paths)
		print(self.path_on)

	def reset_graph(self):
		self.canva.delete(tk.ALL)
		self.draw_nodes()
		self.draw_edges()
		self.draw_paths()
		self.canva.update()
	
	def load_file(self):
		f = tkinter.filedialog.askopenfile(mode="r", title="Select Lem_In file", initialdir="../resources/")
		if f != None:
			res = f.read()
			f.close()
			del(self.colony)
			self.colony = Colony()
			self.colony.read_colony(res)
			self.colony.pars_pathways()
			self.get_paths()
			self.reset_graph()

	def load_file_start(self):
		f = tkinter.filedialog.askopenfile(mode="r", title="Select Initial Lem_In file", initialdir="../resources/")
		if f != None:
			res = f.read()
			f.close()
			self.colony = Colony()
			self.colony.read_colony(res)
			self.colony.pars_pathways()
			self.get_paths()

	def draw_paths(self):
		if self.pth_on.get():
			i = 0
			while i < len(self.all_paths):
				self.show_path_no(i)
				i += 1

if __name__ == "__main__":
	root = tk.Tk()
	lemin = LemInGui(root)
	root.mainloop()