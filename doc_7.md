# Program 7: Dijkstra’s Algorithm for Shortest Path

## Data Structure Used
An adjacency matrix is used to represent the weighted graph.  
Arrays are used to store distance values and visited nodes.

## Functions Implemented
minDistance() finds the unvisited node with minimum distance.  
dijkstra() computes the shortest path from the source node.

## Organization of main()
The main function reads the number of vertices.  
It accepts the weighted adjacency matrix.  
It takes the source node as input.  
It calls Dijkstra’s algorithm and prints shortest distances.

## Sample Output

Input:
4
0 1 4 0
1 0 2 7
4 2 0 3
0 7 3 0
0

Output:
0 0
1 1
2 3
3 6