# Before Final Upload
- What do we do with other comments and commands
- error management
		- if p[0] == 'L' error
		- order error (ants->rooms->links)
		- **ROOMS starting or including char "-" ?**
- test environment
# GitHub To-Do
- readme
- python plotter/solver

# Lem_In
## Project Introduction
This project is a part of algorithmic branch within 42 cursus at [Hive Helsinki](https://www.hive.fi/en/).

The project's objective is to teach the participant about a graph design in C, graph traversal and graph flow and pathing algorithms. 
You are given an ant colony in a form of file which specifies amount of ants inhabiting the colony's starting room, amount of rooms 
(vertices) within the colony and the pathways connecting given rooms (edges). The goal is to figure out a way for all ants to cross 
the colony into the End Room in an efficient manner.

[The complete subject's pdf](/resources/lem-in.en.pdf).
### Input

The input file structure is following:
```
	number_of_ants
	the_rooms
	the_links
```

With allowed input lines as follows
```
	Ants are defined: ant_number
	The rooms are defined by: name coord_x coord_y
	The links are defined by: name1-name2
	Comments are defined by: #comment
	Commands are defined by: ##command
```

The room name can contain any printable symbols except ' ', '-', and cannot start with '#' or 'L'.

### Ants movement restrictions
One ant can move to a different room only once per turn (output line) and the room it is moving to has to be empty. Thus capacity of every room is 1 ant 
except the start and end rooms where the capacity is unlimited. Ants cannot cross over each other in a room nor in a corridor (pathway).

If there's multiple paths, they must be utilized as long as the output is more efficient.

### Goal and Output Format
The goal is to output the shortest possible (amount of lines) set of instructions that make all given ants to cross the colony from start to the end.

The output has to follow this format:
```
	number_of_ants
	the_rooms
	the_links

	Lx-y Lz-w Lr-o ...
```

Where x, z, r represents the ant number (from 1 to N) and y, w, o represent rooms' names.

The program should have reasonable execution time, e.g. for 4000 rooms ideally under 3 seconds, over 15 seconds is too much.
(@jnovotny's note: This line is not very accurate and I strongly disagree with it. Since there's no mention about the graph density, 
on which the input size depends greatly. You can have 4k rooms with density 0.1% which results in 8000 lines of input, or with density 5% 
and 400k lines of input or with density 20% and 1,6 million lines of input.)

### Restrictions
Within the mandatory part of this project only following functions of the standard library are allowed to be used:
```
	malloc
	free
	read
	write
	strerror
	perror
	exit
```

For bonus parts any function is allowed as far as their use can be justified.

In no way can the program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).

The program cannot have memory leaks.

All files have to correspond with 42 norm. In brief:
```
	Function can contain maximum of 25 lines
	There can be only 5 function in a .c file
	If a function is used only within one file, it should be defined as static
	Variables have to be defined at the beginning of a function
	Variables cannot be initialized at the same line as their definition
	Max 5 variables per function
	Max 4 parametres per function
	Forbidden stuff: for, do .. while, switch, case, goto
	No Global variables allowed (unless absolutely necessary)
```

## C version
	BFS + Ford-Fulkerson => Edmond-Karp

### To-Do

	Current performance without identical rooms check (24.2.):
	| Map			| Ants	| Time		| Read Time	| Read & Check Input |
	|---------------|-------|----------:|----------:|-------------------:|
	| lem_map_1kd10 | 100	| 2.146		|
	| lem_map_1kd10 | 1000	| 2.370		|
	| lem_map_1kd10 | 10000	| 2.788		|
	| lem_map_4k_01 | 100	| 1.570		|
	| lem_map_4k_01 | 1000	| 1.788		|
	| lem_map_4k_01 | 10000	| 2.610		|
	| lem_map_4kd5	| 100	| 54.103	| 
	| lem_map_4kd5	| 1000	| 52.648	| 41.620	| 42.243			|
	| lem_map_4kd5	| 10000	| 56.705	|
	| lem_map_4kd5	| 100000| 1:08.28	|

	New Solution Checking & Reading/Output(unorg) (24.2.):
	| Map			| Ants	| Time		| Read Time	| Read & Check Input |
	|---------------|-------|----------:|----------:|-------------------:|
	| lem_map_1kd10 | 100	| 1.672		|
	| lem_map_1kd10 | 1000	| 1.625		|
	| lem_map_1kd10 | 10000	| 2.025		|
	| lem_map_4k_01 | 100	| 1.564		|
	| lem_map_4k_01 | 1000	| 1.616		|
	| lem_map_4k_01 | 10000	| 2.417		|
	| lem_map_4kd5	| 100	| 45.039	| 
	| lem_map_4kd5	| 1000	| 45.804	|
	| lem_map_4kd5	| 10000	| 45.801	| 38.799
	| lem_map_4kd5	| 100000| 52.506	|

	New Malloc system for creating links (26.2.):
	| Map			| Ants	| Time		| Read Time	| Read & Check Input |
	|---------------|-------|----------:|----------:|-------------------:|
	| lem_map_1kd10 | 100	| 1.500		|
	| lem_map_1kd10 | 1000	| 1.544		|
	| lem_map_1kd10 | 10000	| 1.886		|
	| lem_map_4k_01 | 100	| 1.520		|
	| lem_map_4k_01 | 1000	| 1.584		|
	| lem_map_4k_01 | 10000	| 2.300		|
	| lem_map_4kd5	| 100	| 43.738	| 
	| lem_map_4kd5	| 1000	| 43.198	|
	| lem_map_4kd5	| 10000	| 44.018	| 36.616
	| lem_map_4kd5	| 100000| 51.130	|
	| lem_map_10k25d| 100000| 


	- error management
		- if p[0] == 'L' error (done)
		- order error (ants->rooms->links)
		- **ROOMS starting or including char "-" ?**
		- DUPLICATE rooms (done)
		- coordinates over int range (done)
		- duplicate paths (ignore)
		- not enough data error
			- mandatory start and end (done)
			- number of ants and only once(done)
		- no solution
	- test environment

## Random notes
the starting (ending) amount of paths will determine the mode
	- one path means only one ant can exit the starting node at the time
		-> shortest path (BFS)
	- multiple paths -> max flow
	- min(start_neighbors, end_neigbors) => amount of shortest paths needed
		-> check if utilizing them is worth it

[Unit test](https://github.com/TBouder/lem-in_test)

[Python Test?](https://www.geeksforgeeks.org/python-clustering-connectivity-and-other-graph-properties-using-networkx/)

## Eval 2018

- author file
- reading on the standard output
	e.g. ./lem_in < ant_farm.txt
- Error management
	- No rooms
	- No ants
	- No mandatory comments
	- No possible solution
- Comment management
	- Comments
	- Commands (accepts other commands than stard and end)
- Output format
	- Ant-famr composition
	- commands and comments
	- ants movements
		- 1 line per turn
		- N movements per turn
		- Lx-y where x is the ant's number and y the room's number
- Algorithm's accuracy
	- The path is valid
		- The solution is making the ants properly go from start to end
		- Ants aren't walking on each other (one ant per room at the time)
		- At the end all ants are in the end room
- Bonus
	- A very efficient algorithm
	- Graphic visualiser (if well made can be worth more than 1 point)


## VISU-HEXX controls

1- show all connections
2- show valid paths (not necessarily used)
arrow right- (if not paused move ants one step)
space- play/ pause button (ants will move automatically)
arrow left- toggle room and ant names

## Python Version
Plotting graph
Finds all unique shortest paths that can be utilized
Assigns Ants to correct paths
Prints desired output for moving ants across the graph

