///NOTE: Index represents node and it's orresponding value representas parent/root
/*
    Kruskal’s Algorithm - Minimum Cost Spanning Tree (MST)
    ------------------------------------------------------
    Algorithm Used: 
    - Kruskal’s Algorithm (Greedy Approach, Disjoint Set Union-Find)

    Time Complexity: 
    - O(E log E) due to sorting edges and performing union-find operations.
    - Suitable for sparse graphs compared to Prim’s Algorithm.

    Input:
    - Cost Adjacency Matrix: Represents the graph with edge weights.
    - User inputs the number of vertices and adjacency matrix values.

    Output:
    - Displays the edges included in the Minimum Cost Spanning Tree (MST).
    - Prints the total minimum cost of the spanning tree.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 99999

int i, j, a, b, u, v, n, ne = 1;
int mincost = 0, cost[MAX][MAX], parent[MAX];

int find(int i) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskal() {
    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
    
    while (ne < n) {
        int min = INF;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {// uni(u, v) returns 1 only if u and v are not belonging to the same union
            printf("Edge %d: (%d - %d) Cost: %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF;  // Mark edge as used
    }

    printf("\nMinimum cost of spanning tree = %d\n", mincost);
}

int main() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF; // Replace 0 with INF for unconnected nodes
            }
        }
    }

    kruskal();
    return 0;
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
    The edges of Minimum Cost Spanning Tree are:
    Edge 1: (1 - 3) Cost: 5
    Edge 2: (3 - 2) Cost: 15
    Edge 3: (2 - 0) Cost: 10

    Minimum cost of spanning tree = 30
*/
