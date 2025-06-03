/*
Question 1.b) Write a program using pointer for searching the desired element from the array using pointer.
*/

#include <stdio.h>
void search(int *,int *,int *);

int main() {
    int num,i,a[10],key;
    printf("Enter the number of elements to the array\n");
    scanf("%d",&num);
    printf("Enter the elements to the array\n");
    for(i=0;i<num;i++)
        scanf("%d",&a[i]);
    printf("Enter element to be search\n");
    scanf("%d",&key);
    search(a,&num,&key);
    return 0;
}

void search(int *arr,int *n,int *ele)
{
    int i, flag=0;
    for(i=0;i<*n;i++)
    {
        if(*arr==*ele)
        {
            flag=1;
            printf("Element %d found at position %d",*ele,i+1);
            break;
        }
        arr++;
    }
    if(flag==0)
        printf("Element not found");
}

/*
Output1:
Enter the number of elements to the array
5
Enter the elements to the array
1
2
3
4
5
Enter element to be search
5
Element 5 found at position 5

Output2:
Enter the number of elements to the array
3
Enter the elements to the array
5
9
4
Enter element to be search
3
Element not found
*/