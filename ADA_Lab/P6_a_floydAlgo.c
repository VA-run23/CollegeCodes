#include <stdio.h>

#define INF 99999
#define MAX 10

/*
    Floyd-Warshall Algorithm - All Pairs Shortest Paths
    ---------------------------------------------------
    Algorithm Used: 
    - Floyd-Warshall Algorithm (Dynamic Programming Approach)

    Time Complexity: 
    - O(V³), where V is the number of vertices.
    - The algorithm iterates through three nested loops for all vertex pairs, making it cubic in complexity.

    Input:
    - Cost Matrix (Adjacency Matrix): Represents the initial graph where edge weights are stored.
    - INF (infinity) indicates no direct edge between two vertices.
    - The user inputs the number of vertices, number of edges, and edge weights.

    Output:
    - Adjacency Matrix (After Floyd-Warshall Execution): Displays the shortest distances between all vertex pairs.
    - If there is no possible path between two vertices, INF is maintained.
    - The program prints the shortest path between each pair of vertices.
*/


void floyds(int p[MAX][MAX], int n) {
    int i, j, k;
    
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (p[i][k] != INF && p[k][j] != INF) {
                    p[i][j] = (p[i][j] > p[i][k] + p[k][j]) ? (p[i][k] + p[k][j]) : p[i][j];
                }
            }
        }
    }
}

int main() {
    int p[MAX][MAX], w, n, e, u, v, i, j;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix with INF
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                p[i][j] = 0;
            } else {
                p[i][j] = INF;
            }
        }
    }

    // Taking edge weight input
    for (i = 0; i < e; i++) {
        printf("\nEnter the end vertices of edge %d with its weight: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        p[u][v] = w;
    }

    printf("\nCost Matrix (Input Adjacency Matrix):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (p[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", p[i][j]);
            }
        }
        printf("\n");
    }

    floyds(p, n);

    printf("\nShortest Paths Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (p[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", p[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nThe shortest paths are:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                printf("<%d,%d> = %d\n", i, j, (p[i][j] == INF) ? -1 : p[i][j]);
            }
        }
    }

    return 0;
}
