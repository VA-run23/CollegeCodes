/*
    Dijkstra’s Algorithm - Shortest Path in Weighted Graph
    ------------------------------------------------------
    Algorithm Used: 
    - Dijkstra’s Algorithm (Greedy Approach)

    Time Complexity: 
    - O(V²) for adjacency matrix implementation.
    - Can be optimized to O(E log V) using priority queues (Heap-based).

    Input:
    - Cost Matrix (Adjacency Matrix): Represents edge weights.
    - User inputs the number of vertices, adjacency matrix values, and source vertex.

    Output:
    - Displays the shortest path cost from the source vertex to all other vertices.
*/

#include <stdio.h>

#define MAX 10
#define INF 99999

void dijkstra(int n, int v, int cost[MAX][MAX], int dist[MAX]) {
    int flag[MAX] = {0}, min, u, count = 1, i, w;

    // Initialize distances
    for (i = 0; i < n; i++) {
        dist[i] = cost[v][i];
    }

    flag[v] = 1;  // Mark source vertex as visited

    while (count < n) {
        min = INF;

        for (w = 0; w < n; w++) {
            if (!flag[w] && dist[w] < min) {//here flag[w] is used to check if the vertex is already visited
                min = dist[w];
                u = w;
            }
        }

        flag[u] = 1;
        count++;

        for (w = 0; w < n; w++) {
            if (!flag[w] && (dist[u] + cost[u][w] < dist[w])) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    int n, v, i, j, cost[MAX][MAX], dist[MAX];

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF; // Replace 0 with INF for unconnected nodes
            }
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    dijkstra(n, v, cost, dist);

    printf("\nShortest Paths from vertex %d:\n", v);
    for (i = 0; i < n; i++) {
        if (i != v) {
            printf("%d -> %d, Cost = %d\n", v, i, dist[i]);
        }
    }

    return 0;
}

/*
    // INPUT:
    Enter the number of nodes: 4

    Enter the cost matrix:
    0 10 20 0
    10 0 30 5
    20 30 0 15
    0 5 15 0

    Enter the source vertex: 0

    // OUTPUT:
    Shortest Paths from vertex 0:
    0 -> 1, Cost = 10
    0 -> 2, Cost = 20
    0 -> 3, Cost = 15
*/

