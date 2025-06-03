/* Question 7b) Write a C program to implement a circular queue using linked lists. */

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num;
    struct node *next;
}NODE;
void insertrear( int);
void deletefront( );
void display( );
NODE *front=NULL, *rear=NULL;
void main()
{
    int num, choice;
    while(1)
    {
        printf("\nEnter your choice\n");
        printf("1. Insert at rear\n");
        printf("2. Delete at front\n");
        printf("3. Display\n");
        printf("4. Stop\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf(" Enter data to insert\n");
                    scanf("%d",&num);
                    insertrear(num);
                    break;
            case 2: deletefront();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
        }
    }
}
void insertrear(int n)
{
    NODE *new_node;
    new_node = (NODE *) malloc(sizeof(struct node));
    new_node ->num = n;
    new_node ->next = front;
    if((front == NULL) &&(rear == NULL)) // If List empty
    {
        front = rear = new_node ;
        front->next = front;
    }
    rear->next = new_node ; // One or more nodes, link rear node to new_node
    new_node ->next = front; // link new node node to front
    rear = new_node ; // Make temp node as rear
    return ;
}
void deletefront()
{
    NODE *ptr;
    if((front == NULL) &&(rear == NULL))
    {
        printf("Queue Empty\n");
    }
    else if(front->next == front) // only one node
    {
        printf("Item deleted: %d\n",front->num);
        free(front);
        front = rear = NULL;
    }
    else
    { // more than 1 nodes
        ptr = front;
        front = front->next; // Make the second node as front node
        rear->next = front; // Link last node to the new front node
        printf("Item deleted: %d\n",ptr->num);
        free(ptr);
    }
    return ;
}
void display( )
{
    NODE *ptr;
    ptr = front;
    if (ptr == NULL)
        printf("Queue empty\n");
    else
    {
        printf("The Queue data are\n");
        do
        {
            printf("%d ", ptr ->num);
            ptr = ptr ->next;
        }
        while(ptr != front);
    }
    return;
}

/* OUTPUT:
Enter your choice
1. Insert at rear
2. Delete at front
3. Display
4. Stop
1
Enter data to insert
10

Enter your choice
1. Insert at rear
2. Delete at front
3. Display
4. Stop
1
Enter data to insert
20

Enter your choice
1. Insert at rear
2. Delete at front
3. Display
4. Stop
1
Enter data to insert
30

Enter your choice
1. Insert at rear
2. Delete at front
3. Display
4. Stop
3
The Queue data are
10 20 30

Enter your choice
1. Insert at rear
2. Delete at front
3. Display
4. Stop
2
Item deleted: 10

Enter your choice
1. Insert at rear
2. Delete at front
3. Display
4. Stop
2
Item deleted: 20

Enter your choice
1. Insert at rear
2. Delete at front
3. Display
4. Stop
2
Item deleted: 30

Enter your choice
1. Insert at rear
2. Delete at front
3. Display
4. Stop
2
Queue Empty

Enter your choice
1. Insert at rear
2. Delete at front
3. Display
4. Stop
4
*/