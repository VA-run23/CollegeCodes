/* Question 7a) Write a C program to simulate the working of a queues using an array provide and implement the following operation:
i) Insert
ii) Delete
iii) Display
Assume that the size of the queue is 5. */

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX], front=-1, rear=-1;
void insert(int);
void delete();
void display();
int main()
{
    int choice,num;
    while(1)
    {
        printf(" \n1.INSERT\n2.DELETE \n3.DISPLAY \n4.EXIT");
        printf("\nEnter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter value to insert ");
                    scanf("%d",&num);
                    insert(num);
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("\n EXIT POINT\n");
                    exit(0);
            default: printf ("\nEnter Valid Choice\n");
        }
    }
    return 0;
}
void insert (int num)
{
    if(rear == MAX-1)
    {
        printf("\n OVERFLOW");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = num;
}
void delete( )
{ 
    int val;
    if(front == -1 || front>rear)
    {
        printf("\n UNDERFLOW");
    }
    else
    {
        val = queue[front];
        printf("Deleted Item %d", val);
        front++;
        if(front > rear)
        {
            front = rear = -1;
        }
    }
}
void display( )
{
    int i;
    if(front == -1 || front > rear)
    {
        printf("\n QUEUE EMPTY");
    }
    else
    {
        printf("Queue data \n");
        for(i = front; i <= rear; i++)
        {
            printf("\t %d", queue[i]);
        }
    }
}

/* OUTPUT:
1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:1
Enter value to insert 10

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:1
Enter value to insert 20

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:1
Enter value to insert 30

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:1
Enter value to insert 40

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:1
Enter value to insert 50

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:1
Enter value to insert 60
OVERFLOW

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:3
Queue data
10 20 30 40 50

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:2
Deleted Item 10

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:2
Deleted Item 20

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:2
Deleted Item 30

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:2
Deleted Item 40

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:2
Deleted Item 50

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:2
UNDERFLOW

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:3
QUEUE EMPTY

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice:4
EXIT POINT
*/