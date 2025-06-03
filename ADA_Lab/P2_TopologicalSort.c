/*
    Topological Sorting - Kahn’s Algorithm (Using Indegree)
    --------------------------------------------------------
    Algorithm Used: 
    - Kahn’s Algorithm (Graph Traversal)

    Time Complexity: 
    - O(V + E) where V is the number of vertices and E is the number of edges.
    - Efficient for Directed Acyclic Graphs (DAG).

    Input:
    - Adjacency Matrix: Represents the directed graph with edge connections.
    - User inputs the number of vertices and adjacency matrix values.

    Output:
    - Displays the topological order of the given graph.
    - If the graph has cycles, topological sorting is not possible.
*/

#include <stdio.h>

#define MAX 10

int a[MAX][MAX], n, indegree[MAX];

void find_indegree() {
    int i, j, sum;
    
    for (j = 0; j < n; j++) {
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += a[i][j];
        }
        indegree[j] = sum;
    }
}

void topology() {
    int i, u, v, t[MAX], s[MAX], top = -1, k = 0;// s[] is acting as a stack

    
    find_indegree();

    // Push all nodes with 0 indegree to stack
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            s[++top] = i;
        }
    }

    while (top != -1) {
        u = s[top--];//Pop from the stack and assign to u
        t[k++] = u;//assign u to t[k], where t[k] is the topological order

        for (v = 0; v < n; v++) {
            if (a[u][v] == 1) {//If there is an edge from u to v
                indegree[v]--;
                if (indegree[v] == 0) {
                    s[++top] = v;
                }
            }
        }
    }

    printf("\nThe topological order is:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
}

int main() {
    int i, j;

    printf("Enter number of jobs (vertices): ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    topology();

    return 0;
}

/*
    // INPUT:
    Enter number of jobs (vertices): 4

    Enter the adjacency matrix:
    0 1 1 0
    0 0 0 1
    0 0 0 1
    0 0 0 0

    // OUTPUT:
    The topological order is:
    0 1 2 3
*/

///GRAPHICAL: REPRESENTATION
//      1
//     / \
//    2   3
//     \ /
//      4
