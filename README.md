# Lem_In

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
	| lem_map_4kd5	| 100000| 52.968	|

	lem_map_4kd5 segfaults sometimes in reading process when adding neighbors

#### branch refactor1_0
	- Change xt->elems order 
		- [x] start 1st node
		- [x] end last node
		- [x] keep pointer to both ends
		- [ ] could save time if sorted?
		
		- bfs and ford-fulkerson tidy up
			-[x] return and runtime of bfs
			- memory optimization in total
			- change checking of solution from assigning one ant per iteration to assign all ants to given path at once
		
		- SEGFAULT ON 4kd5!!!!! (solved)
		
		- optional
			- flags
				- debug
				- multithread?
			- introduce room_id so we dont have to care about identical names of rooms, coords must be identical

	- visuhex -> pathdrawing vs ants movement
	- error management
		- **ROOMS starting or including char "-" ?**
		- DUPLICATE rooms (done)
		- coordinates over int range (done)
		- duplicate paths (ignore)
		- not enough data error
			- mandatory start and end (done)
			- number of ants and only once(done)
		- no solution
	- check unique paths
		- limit the BFS search? min(start->ngb, end->ngb)
			- once the limit of unique path is reached, stop bfs
	- split ants among the paths
		- figure out whether we make the ants literally or just abstract somehow
	- output
	- memory leaks check
	- test bfs consistency
	- test environment

### Done
	- prototype BFS that should return all shortest paths.

## Random notes
the starting (ending) amount of paths will determine the mode
	- one path means only one ant can exit the starting node at the time
		-> shortest path (BFS)
	- multiple paths -> max flow
	- min(start_neighbors, end_neigbors) => amount of shortest paths needed
		-> check if utilizing them is worth it

[Unit test](https://github.com/TBouder/lem-in_test)

[Python Test?](https://www.geeksforgeeks.org/python-clustering-connectivity-and-other-graph-properties-using-networkx/)

Amount of turns required for N ants
Distribute ants

## Constrains/ General
- no memory leaks
- Allowed:
		malloc
		free
		read
		write
		strerror
		perror
		exit
	- plus whatever for bonus

## Mandatory part
- Quickest way for N ants to move across
	- from start to end
	- least number of lines (turns)
	- all ants are in ##start at the beginning
	- Turn
		- Each turn dispaly only moved ants
		- each ant can be moved only once and through a tube
			- receiving room must be empty
- Output
'''
	number_of_ants
	the_rooms
	the_links

	Lx-y Lz-w Lr-o ...
'''

- 4000 rooms. 2 or 3 seconds is great, 9 seconds is mediocre, 15 seconds is too much.
	- 10k+ lines

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

