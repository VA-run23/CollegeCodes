/*
    0/1 Knapsack Problem - Dynamic Programming Approach
    ---------------------------------------------------
    Algorithm Used: 
    - Dynamic Programming (Bottom-Up Approach)

    Time Complexity: 
    - O(N * W), where N is the number of items and W is the knapsack capacity.
    - Efficient compared to brute-force exponential solutions.

    Input:
    - User inputs the number of items.
    - For each item, the profit and weight are provided.
    - Knapsack capacity is given as input.

    Output:
    - Displays the total profit achieved.
    - Shows the items included in the optimal solution.
*/

#include <stdio.h>

#define MAX 10

int w[MAX], p[MAX], v[MAX][MAX], n, cap, x[MAX] = {0};

int max(int i, int j) {
    return (i > j) ? i : j;
}

int knap(int i, int j) {
    int value;
    
    if (v[i][j] < 0) {
        if (j < w[i]) {
            value = knap(i - 1, j);
        } else {
            value = max(knap(i - 1, j), p[i] + knap(i - 1, j - w[i]));
        }
        v[i][j] = value;
    }
    
    return v[i][j];
}

int main() {
    int i, j, profit;

    printf("\nEnter the number of items: ");
    scanf("%d", &n);

    printf("Enter the profit and weight of each item:\n");
    for (i = 1; i <= n; i++) {
        printf("For item %d:\n", i);
        scanf("%d %d", &p[i], &w[i]);
    }

    printf("\nEnter the knapsack capacity: ");
    scanf("%d", &cap);

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= cap; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else {
                v[i][j] = -1;
            }
        }
    }

    profit = knap(n, cap);

    i = n;
    j = cap;

    while (j != 0 && i != 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[i] = 1;
            j -= w[i];
        }
        i--;
    }

    printf("\nItems included are:\n");
    printf("Sl.no\tWeight\tProfit\n");
    
    for (i = 1; i <= n; i++) {
        if (x[i]) {
            printf("%d\t%d\t%d\n", i, w[i], p[i]);
        }
    }

    printf("\nTotal profit is: %d\n", profit);
    
    return 0;
}

/*
    // INPUT:
    Enter the number of items: 4

    Enter the profit and weight of each item:
    For item 1:
    10 2
    For item 2:
    20 3
    For item 3:
    30 4
    For item 4:
    40 5

    Enter the knapsack capacity: 7

    // OUTPUT:
    Items included are:
    Sl.no   Weight  Profit
    2       3       20
    3       4       30

    Total profit is: 50
*/
