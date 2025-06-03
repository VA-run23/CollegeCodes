/*
Question 1.c) Write a program to find maximum element in each row of the matrix using pointers.
*/

#include <stdio.h>
void maximum(int (*a)[10],int *r,int*c)
{
    int i=0,j,max=0,res[20];
    for(i=0;i<*r;i++)
    {
        for(j=0;j<*c;j++)
        {
            if(a[i][j]>max)
            {
                max=a[i][j];
            }
        }
        res[i]=max;
        max=0;
    }
    printf("Maximum element in each row is:\n");
    for(i=0;i<*r;i++)
    {
        printf("%d\n",res[i]);
    }
}

int main() {
    int arr[10][10],m,n,i,j;
    printf("Enter the number of rows and coloumns\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elemnts to the matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    }
    maximum(arr,&m,&n);
    return 0;
}

/*
Output:
Enter the number of rows and coloumns
2
3
Enter the elemnts to the matrix
1
2
3
4
5
6
Maximum element in each row is:
3
6
*/