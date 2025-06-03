/*
    Selection Sort Algorithm - Sorting Method
    ----------------------------------------
    Algorithm Used: 
    - Selection Sort (Iterative Approach)

    Time Complexity: 
    - O(N²) in the worst and average case.
    - O(N) in the best case when the array is already sorted.

    Input:
    - User inputs the number of elements.
    - The program generates random numbers within a specified range.

    Output:
    - Displays the original list of randomly generated numbers.
    - Shows the sorted list in ascending order.
    - Computes and prints the time taken for sorting.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int array[], int size) {
    int i, j, minIndex, temp;
    
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

int main() {
    int n, i;
    clock_t st, et;
    double ts;

    printf("\nEnter how many numbers: ");
    scanf("%d", &n);
    
    int a[n];  // Using dynamic array size

    printf("\nThe Random Numbers are:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 1000;  // Limiting the random range for readability
        printf("%d\t", a[i]);
    }

    st = clock();
    selectionSort(a, n);
    et = clock();

    ts = (double)(et - st) / CLOCKS_PER_SEC;
    
    printf("\nSorted Numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    
    printf("\nThe time taken is %e seconds\n", ts);

    return 0;
}

/*
    // INPUT:
    Enter how many numbers: 5

    The Random Numbers are:
    932    423    875    234    789    

    // OUTPUT:
    Sorted Numbers are:
    234    423    789    875    932    

    The time taken is 0.000002 seconds
*/
