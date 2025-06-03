/*
    N-Queens Problem - Backtracking Approach
    ----------------------------------------
    Algorithm Used: 
    - Backtracking (Iterative Approach)

    Time Complexity: 
    - O(N!) in the worst case as the algorithm explores all possible placements.

    Input:
    - User inputs the number of queens (N).
    - The board is initialized with an empty configuration.

    Output:
    - Displays all possible solutions where N queens are safely placed without attacking each other.
*/

#include <stdio.h>
#include <math.h>

#define MAX 30   // Maximum allowed number of queens

int a[MAX];      // Array to store column positions of queens for each row
int count = 0;   // Solution counter

/*
    Function: place()
    -----------------
    This function checks if a queen can be placed at the given row index (pos)
    without conflicting with previously placed queens.

    Parameters:
    - pos: The current row in which the queen is being placed.

    Returns:
    - 1 if placement is valid (safe), otherwise 0 (unsafe).
*/

int place(int pos) { // pos represents the row index where the current queen is being placed
    int i;

    /*
        Loop through all previously placed queens to check for conflicts.
        i represents row indices of previously placed queens (from row 1 to pos-1).
        a[i] stores column positions of these queens.
    */
    for (i = 1; i < pos; i++) {
        // Rule 1: Check for same column conflict
        // If the queen at row pos shares the same column as any previous queen at row i, placement is unsafe.
        if (a[i] == a[pos]) {
            return 0; // Unsafe placement
        }

        // Rule 2: Check for diagonal conflict
        // If the absolute difference between the column positions of two queens
        // equals the absolute difference between their row positions, it means they are diagonally aligned.
        if (abs(a[i] - a[pos]) == abs(i - pos)) {
            return 0; // Unsafe placement
        }
    }

    return 1;  // Placement is safe
}


/*
    Function: print_solution()
    --------------------------
    This function prints the current valid arrangement of N queens.

    Parameters:
    - n: The number of queens (N).
*/
void print_solution(int n) {
    int i, j;
    count++;  // Increment solution counter

    printf("\n\nSolution #%d:\n", count);
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i] == j) {
                printf("Q\t"); // Queen placement
            } else {
                printf("*\t"); // Empty cell
            }
        }
        printf("\n");
    }
}

/*
    Function: queen()
    -----------------
    This function implements the backtracking approach iteratively to find all solutions.

    Parameters:
    - n: The number of queens (N).
*/
void queen(int n) {
    int k = 1;   // Row counter
    a[k] = 0;    // Initializing column position of first queen

    while (k != 0) { // Continue until all possibilities are exhausted
        a[k]++;  // Move queen to the next column

        // Check validity of the current placement
        while ((a[k] <= n) && !place(k)) {//finding till a safe place is found and it is within the board
            a[k]++;
        }

        if (a[k] <= n) {  // If a valid position is found
            if (k == n) {  // If all queens are placed in all rows
                print_solution(n); // Print the solution
            } else {
                k++;   // Move to the next row
                a[k] = 0;  // Initialize column position for the next queen
            }
        } else {
            k--;  // Backtrack to the previous row to try a different position
        }
    }
}

/*
    Function: main()
    ----------------
    Entry point of the program where the user provides the number of queens.
*/
int main() {
    int n;
    
    printf("Enter the number of Queens: ");
    scanf("%d", &n);

    queen(n);  // Solve the N-Queens problem

    printf("\nTotal solutions = %d\n", count); // Display total solutions found

    return 0;
}
