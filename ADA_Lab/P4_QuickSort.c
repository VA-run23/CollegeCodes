/*
    Quick Sort Algorithm - Sorting Method
    ----------------------------------------
    Algorithm Used: 
    - Quick Sort (Divide and Conquer Approach)

    Time Complexity: 
    - O(N log N) in the average and best case.
    - O(N²) in the worst case when the pivot selection is poor (sorted or reverse-sorted array).

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

void Exch(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void QuickSort(int a[], int low, int high) {
    if (low >= high) {
        return;
    }

    int key = a[low]; // Pivot selection
    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= high && a[i] <= key) {
            i++;
        }
        while (a[j] > key) {
            j--;
        }
        if (i < j) {
            Exch(&a[i], &a[j]);
        }
    }

    Exch(&a[low], &a[j]);  // Swap pivot to correct position
    QuickSort(a, low, j - 1);
    QuickSort(a, j + 1, high);
}

int main() {
    int n, i;
    clock_t st, et;
    double ts;

    printf("\nEnter how many numbers: ");
    scanf("%d", &n);

    int a[n];  // Dynamic array allocation

    printf("\nThe Random Numbers are:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 1000;  // Limiting random range for readability
        printf("%d\t", a[i]);
    }

    st = clock();
    QuickSort(a, 0, n - 1);  // Corrected indexing (starting from 0)
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

    The time taken is 0.000004 seconds
*/
