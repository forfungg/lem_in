import sys
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from matplotlib.animation import FuncAnimation
from srcs.colony import Colony
plt.style.use('seaborn-pastel')

def	read_lemin():
	ret = ""
	for line in sys.stdin:
		ret += line
	return ret

if __name__ == "__main__":
	n = 8
	x = [19, 16, 16, 13, 9, 1, 4, 9]
	y = [3, 7, 3, 5, 3, 5, 8, 5]
	names = ['1', '2', '3', '4', '5', '6', '7', '0']
	ngb = [['2'],['3'],['4'],['5'],['6', '7'],['7'],['0'],[]]

	data = dict()
	data['Names'] = names
	data['X'] = x
	data['Y'] = y
	data['NGB'] = ngb
	df = pd.DataFrame(data)
	print(df)
	# to_plot = df[['X', 'Y']].copy()
	# print(to_plot.applymap(type))
	# 
	# print(to_plot)
	df.plot(kind='scatter', x='X', y='Y', marker='o', color='red')
	plt.show()
	# plt.plot(x, y, marker='o')
	# plt.title('lem_in visualiser')
	# plt.ylabel('y - coordinates')
	# plt.xlabel('x - coordinates')
	# plt.show()