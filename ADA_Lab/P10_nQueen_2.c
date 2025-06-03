/*
    N-Queens Problem - Easy to Understand Version
    ==============================================
    
    WHAT THIS PROGRAM DOES:
    - Places N queens on an N×N chessboard
    - Makes sure no queen can attack any other queen
    - Queens can attack horizontally, vertically, and diagonally
    - Finds ALL possible solutions
    
    HOW WE REPRESENT THE BOARD:
    - We don't store the entire board in memory
    - Instead, we use array a[] where:
      * a[1] = column number of queen in row 1
      * a[2] = column number of queen in row 2
      * and so on...
    - Example: If a[3] = 5, it means there's a queen at row 3, column 5
*/

#include <stdio.h>
#include <math.h>

#define MAX 30   // We can handle up to 30 queens maximum

// GLOBAL VARIABLES
int a[MAX];      // This array stores WHERE each queen is placed
                 // a[row] = column_number
int count = 0;   // Counts how many solutions we've found

/*
    FUNCTION: place(pos)
    ====================
    PURPOSE: Check if we can safely place a queen in row 'pos'
    
    SIMPLE EXPLANATION:
    - We want to place a queen in row 'pos' at column a[pos]
    - Before we do that, we check: "Will this new queen attack any existing queens?"
    - We only check queens in rows ABOVE the current row (rows 1 to pos-1)
    - Why only above? Because we place queens row by row, top to bottom
    
    WHAT MAKES QUEENS ATTACK EACH OTHER:
    1. Same column (vertical attack)
    2. Same diagonal (diagonal attack)
    
    RETURNS: 1 if safe to place, 0 if not safe
*/
int place(int pos) {
    int i;

    // Check against ALL previously placed queens
    // 'i' goes through each row that already has a queen (1 to pos-1)
    for (i = 1; i < pos; i++) {
        
        // RULE 1: Check if they're in the same column
        // If queen in row 'i' and queen in row 'pos' have same column number,
        // they will attack each other vertically
        if (a[i] == a[pos]) {
            return 0; // Not safe! Same column attack
        }

        // RULE 2: Check if they're on the same diagonal
        // Two queens are on same diagonal if:
        // The horizontal distance equals the vertical distance
        // 
        // Example: Queen at (2,3) and Queen at (4,5)
        // Horizontal distance = |3-5| = 2
        // Vertical distance = |2-4| = 2
        // Since 2 == 2, they're on same diagonal!
        if (abs(a[i] - a[pos]) == abs(i - pos)) {
            return 0; // Not safe! Diagonal attack
        }
    }

    return 1;  // Safe to place the queen here!
}

/*
    FUNCTION: print_solution(n)
    ===========================
    PURPOSE: Display the current solution in a nice visual format
    
    HOW IT WORKS:
    - Goes through each row and column of the board
    - Prints 'Q' where there's a queen, '*' where it's empty
    - Uses our array a[] to know where queens are placed
*/
void print_solution(int n) {
    int i, j;
    count++;  // Increment our solution counter

    printf("\n\nSolution #%d:\n", count);
    
    // For each row of the chessboard
    for (i = 1; i <= n; i++) {
        // For each column in this row
        for (j = 1; j <= n; j++) {
            // Is there a queen in this position?
            // Check: does the queen in row 'i' sit in column 'j'?
            if (a[i] == j) {
                printf("Q\t"); // Yes! Print the queen
            } else {
                printf("*\t"); // No queen here, print empty space
            }
        }
        printf("\n"); // Move to next row
    }
}

/*
    FUNCTION: queen(n) - THE MAIN ALGORITHM
    =======================================
    PURPOSE: Find all possible ways to place n queens safely
    
    STRATEGY: Try every possible position systematically
    - Start with row 1, try columns 1, 2, 3, ..., n
    - When we find a safe spot, move to next row
    - If we can't find a safe spot, go back to previous row (BACKTRACK)
    
    VARIABLES EXPLAINED:
    - k: Current row we're working on
    - a[k]: Column position we're trying for row k
*/
void queen(int n) {
    int k = 1;   // Start with row 1
    a[k] = 0;    // Start with column 0 (will become 1 when we increment)

    // Keep going until we've tried everything (k becomes 0 means we're done)
    while (k != 0) {
        
        // TRY NEXT COLUMN in current row
        a[k]++;  // Move to next column position
        
        // FIND A SAFE POSITION in current row
        // Keep trying columns until we find a safe one OR run out of columns
        while ((a[k] <= n) && !place(k)) {
            a[k]++; // This column doesn't work, try next one
        }
        
        // DID WE FIND A SAFE POSITION?
        if (a[k] <= n) {  // Yes! We found a valid column
            
            // ARE WE DONE WITH ALL ROWS?
            if (k == n) {  // Yes! We've placed all n queens successfully
                print_solution(n); // Show this solution
                // Don't stop here - continue to find more solutions
            } else {
                // NOT DONE YET - move to next row
                k++;       // Go to next row
                a[k] = 0;  // Start trying from column 1 (will become 1 after a[k]++)
            }
            
        } else {
            // NO SAFE POSITION FOUND in current row
            // This means our previous choices led to a dead end
            // BACKTRACK: Go back to previous row and try different column
            k--;  // Go back one row
            // The loop will continue and try next column in the previous row
        }
    }
}

/*
    MAIN FUNCTION
    =============
    Simply gets input from user and starts the solving process
*/
int main() {
    int n;
    
    printf("Enter the number of Queens: ");
    scanf("%d", &n);

    printf("\nFinding all solutions for %d queens on %dx%d board...\n", n, n, n);
    
    queen(n);  // Start solving!

    printf("\nTotal solutions found = %d\n", count);

    return 0;
}