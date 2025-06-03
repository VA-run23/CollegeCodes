/*
    Prim’s Algorithm - Minimum Cost Spanning Tree (MST)
    ---------------------------------------------------
    Algorithm Used: 
    - Prim’s Algorithm (Greedy Approach)

    Time Complexity: 
    - O(V²) for adjacency matrix implementation.
    - Can be optimized to O(E log V) using priority queues and adjacency lists.

    Input:
    - Adjacency Matrix: Represents the graph with edge weights.
    - User inputs the number of vertices and adjacency matrix values.

    Output:
    - Displays the edges included in the Minimum Cost Spanning Tree (MST).
    - Prints the total minimum cost of the spanning tree.
*/
#include<stdio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

void main() {
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;  // Assigning a large value to indicate no direct connection
            }
        }
    }

    visited[1] = 1;
    printf("\n");

    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min && visited[i] != 0) {//i th node is visited
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0) {
            printf("\n Edge %d: (%d %d) cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999; // Mark the edge as visited
    }

    printf("\n Minimum cost = %d", mincost);
}

/*
    // INPUT:
    Enter the number of nodes: 4

    Enter the adjacency matrix:
    0 10 20 0
    10 0 30 5
    20 30 0 15
    0 5 15 0

    // OUTPUT:
    The edges in the Minimum Cost Spanning Tree are:
    Edge 1: (1 - 3) Cost: 5
    Edge 2: (3 - 2) Cost: 15
    Edge 3: (2 - 0) Cost: 10

    Minimum cost of spanning tree = 30
*/

