/*
Question 3.b) Write a C program to reverse a linked list elements.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;

NODE* insertfront(NODE *, int);
NODE* reverse(NODE *);
void display(NODE *);

void main()
{
    NODE *start=NULL;
    int num,choice;
    while(1)
    {
        printf("Enter your choice\n");
        printf("1. Insert at front\n");
        printf("2. Reverse\n");
        printf("3. Display\n");
        printf("4. Stop\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf(" Enter data to insert\n");
                    scanf("%d",&num);
                    start= insertfront(start,num);
                    break;
            case 2: printf(" Reversed string is\n");
                    start= reverse(start);
                    break;
            case 3: display(start);
                    break;
            case 4: exit(0);
        }
    }
}

NODE* insertfront(NODE *start, int n)
{
    NODE *new_node;
    new_node = (NODE *) malloc(sizeof(struct node));
    new_node ->data = n;
    new_node ->next = start;
    start = new_node;
    return start;
}

NODE* reverse(NODE *start)
{
    NODE *prev, *temp,*ptr;
    if (start == NULL)
    {
        printf("List Empty\n");
        return start;
    }
    if (start->next== NULL)
    {
        printf("only one Node %d\n", start->data);
        return start;
    }
    else
    {
        prev = NULL;
        ptr= start;
        while (ptr != NULL)
        {
            temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        start= prev;
        return start;
    }
}

void display(NODE *start)
{
    NODE *ptr;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    ptr = start;
    printf("The list data are \n");
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

/*
Output:
Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
1
Enter data to insert
11
Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
1
Enter data to insert
22
Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
1
Enter data to insert
33
Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
3
The list data are
33
22
11
Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
2
Reversed string is
Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
3
The list data are
11
22
33
Enter your choice
1. Insert at front
2. Reverse
3. Display
4. Stop
4
*/