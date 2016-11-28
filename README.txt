HW4.1 GRAPH ALGORITHMS: REACHABILITY FROM A SOURCE VERTEX
by Viktor Dahbura
Created: 11/19/2016

-About:
	This C++ program finds the reachable vertices from a source vertex within a given depth in a graph using two alternative aproaches: 
	a) Iteration of row vector-matrix multiplication  
	b) Using a Depth First Search (DFS) algorithm. 
	The input, a directed graph, will be given in a .txt file in the form of a adjaceny sparse (n x n) matrix.

	**Example input file:

	2 1 1
	2 3 1
	3 5 1
	4 5 1
	5 6 1
	5 7 1
	5 8 1
	6 4 1
	7 6 1
	9 5 1
	10 9 1
	11 2 1
	11 11 0

	The approach used to determine reachability is instructed by user input. The following output will be then 
	stored in a separate .txt file in ascending order starting at the source vertex if alternative a) is used, 
	or withouth the source vertex and in path order if b) is used. 

	**Example output file using vector-matrix multiplication with source = 2, and depth = 3 for the above example input:

	1
	2
	3
	5
	6
	7
	8
	
-To compile:
	Command line for compiling in terminal:
	g++ -std=c++11 reachability.cpp -o reachability

-To run:
	Command line to run in terminal given 1 input .txt file:
	reachability "E=<file>;labels=<file>;result=<file>;source=<integer>;dfs=<no|recursive|iterative>;k=<integer>"

	Example:
	./reachability "E=01a.txt;result=Z.txt;source=2;dfs=no;k=3"
	
	**Note:
	If no reachability approach is instructed by the user, vector-matrix multiplication will be used by default.





