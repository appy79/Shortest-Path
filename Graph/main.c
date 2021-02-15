//
//  main.c
//  Graph
//
//  Created by Amandeep on 13/02/21.
//

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 6

// Checking the validity of input values of source and destination
bool check(int src, int dest){
    if(src<=5 && 0<=src && 0<=dest && dest<=5){
        return true;
    }
    else{
        return false;
    }
}

// Finding vertex with minimum distance value from
// the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

// Helps printing the results. Prints each individual vertices coming in the shortest path
void printPath(int parent[], int j)
{
    if (parent[j] == - 1)
        return;
  
    printPath(parent, parent[j]);
  
    printf("->%d", j);
}

// Printing the results
void printSolution(int dist[], int n, int parent[], int src, int dest)
{
    printf("Buildings \t Distance\t Path to traverse");
        printf("\n%d -> %d \t \t %d\t \t \t %d ", src, dest, dist[dest], src);
        printPath(parent, dest);
    printf("\n");
}
  

void dijkstra(int graph[V][V], int src, int dest)
{
    int dist[V];
    bool sptSet[V];
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[src] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    printSolution(dist, V, parent, src, dest);
}
  
// Execution
int main()
{
    // Here the graph represents the distance each building has from other buildings.
    int graph[V][V] = {{0, 2, 4, 6, 8, 10},
                       {2, 0, 8, 2, 9, 3},
                        {4, 8, 0, 7, 2, 4},
                        {6, 2, 7, 0, 9, 14},
                        {8, 9, 2, 9, 0, 10},
                        {10, 3, 4, 14, 10, 0}
                    };
    printf("Enter the number corresponding to building name when asked :- \n 0. Lyceum\n 1. Orion \n 2. Admin Block \n 3. Shopping Complex \n 4. Agate \n 5. Aquamarine \n");
    int src,dest;
    printf("\nSource:-");
    scanf("%d",&src);
    printf("\nDestination:-");
    scanf("%d",&dest);
    printf("\n");
    if(check(src,dest)){
        dijkstra(graph, src, dest);
    }
    else{
        printf("Invalid input for buildings.");
    }
    return 0;
}
