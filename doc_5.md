# Program 5: Undirected Graph Using Adjacency Matrix

## Data Structure Used
An adjacency matrix is used to represent the undirected graph.  
A visited array is used to track visited vertices.

## Functions Implemented
bfs() performs Breadth First Search traversal.  
dfs() performs Depth First Search traversal.

## Organization of main()
The main function reads the number of vertices.  
It takes the adjacency matrix as input.  
It accepts the starting vertex.  
It performs BFS traversal followed by DFS traversal.

## Sample Output

Input:
4
0 1 1 0
1 0 1 0
1 1 0 1
0 0 1 0
0

Output:
0 1 2 3
0 1 2 3