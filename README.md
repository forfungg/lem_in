# Lem_In

## C version

### To-Do
	- check unique paths
		- limit the BFS search? min(start->ngb, end->ngb)
	- test bfs consistency

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


## Python Version
Plotting graph
Finds all unique shortest paths that can be utilized
Assigns Ants to correct paths
Prints desired output for moving ants across the graph
