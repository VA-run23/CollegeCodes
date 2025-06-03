/*
    Warshall’s Algorithm - Transitive Closure
    ----------------------------------------
    Algorithm Used: 
    - Warshall’s Algorithm (Graph Theory, Dynamic Programming)

    Time Complexity: 
    - O(V³), where V is the number of vertices.
    - The algorithm iterates through three nested loops, checking all paths.

    Input:
    - Adjacency Matrix: Represents the graph where edge connectivity is stored.
    - User inputs the number of vertices and adjacency matrix values.

    Output:
    - Transitive Closure Matrix: Displays whether there exists a path between any pair of vertices.
*/

#include <stdio.h>

#define MAX 10

int n, a[MAX][MAX], p[MAX][MAX];

void path() {
    int i, j, k;
    
    // Initialize path matrix with adjacency matrix values
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            p[i][j] = a[i][j];
        }
    }

    // Warshall’s algorithm: updating transitive closure
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (p[i][k] == 1 && p[k][j] == 1) {
                    p[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    path();

    printf("\nThe transitive closure matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// //INPUT:
// Enter the number of nodes: 4

// Enter the adjacency matrix:
// 0 1 0 1
// 0 0 1 0
// 1 0 0 0
// 0 0 1 0


// //OUTPUT:
// The transitive closure matrix is:
// 1 1 1 1
// 1 1 1 1
// 1 1 1 1
// 0 0 1 1
