/*
Question 1.a) Write a program to accept 3 integers and find the maximum among 3 numbers using functions and pointers.
*/

#include <stdio.h>
void large(int *,int *, int *);

int main() {
    int x,y,z;
    printf("Enter three integers\n");
    scanf("%d%d%d",&x,&y,&z);
    large(&x,&y,&z);
    return 0;
}

void large(int *a, int *b, int *c)
{
    if(*a>*b && *a>*c)
        printf("%d is greater",*a);
    else if(*b>*a && *b>*c)
        printf("%d is greater",*b);
    else
        printf("%d is greater",*c);
}

/*
Output:
Enter three integers
9
10
11
11 is greater
*/