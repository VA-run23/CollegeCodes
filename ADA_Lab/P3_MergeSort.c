/*
    Merge Sort Algorithm - Sorting Method
    ----------------------------------------
    Algorithm Used: 
    - Merge Sort (Divide and Conquer Approach)

    Time Complexity: 
    - O(N log N) in all cases (best, worst, and average).
    - Efficient for large datasets due to its stable sorting nature.

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

void Merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low, b[high + 1];

    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];
    
    while (j <= high)
        b[k++] = a[j++];

    for (k = low; k <= high; k++)
        a[k] = b[k];
}

void MergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main() {
    int n, i;
    clock_t st, et;
    double ts;

    printf("\nEnter how many numbers: ");
    scanf("%d", &n);

    int a[n]; // Using dynamic array size

    printf("\nThe Random Numbers are:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 1000; // Limiting the random range for readability
        printf("%d\t", a[i]);
    }

    st = clock();
    MergeSort(a, 0, n - 1); // Corrected indexing (starts from 0)
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

    The time taken is 0.000003 seconds
*/
