/* Question 6c) Write a program to find the nth term in the Fibonacci series using recursion. */

#include <stdio.h>
int Fibonacci(int);
int main()
{
    int n, i = 0, res;
    printf("Enter the number of terms:\n");
    scanf("%d",&n);
    printf("Fibonacci series\n");
    for(i = 0; i < n; i++ )
    {
        res = Fibonacci(i);
        printf("%d\t",res);
    }
    printf("%d\t is the last element in the Series",res);
    return 0;
}
int Fibonacci(int n)
{
    if ( n == 0 )
        return 0;
    else if ( n == 1 )
        return 1;
    else
        return (Fibonacci(n-1) + Fibonacci(n-2));
}

/* OUTPUT:
Enter the number of terms:
7
Fibonacci series
0 1 1 2 3 5 8
8 is the last element in the Series
*/