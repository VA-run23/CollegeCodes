/*
Question 3.a) Write a C program using dynamic variables and pointers, to construct a singly linked list.
The operations to be supported are:
i) Insert at the front of a list.
ii) Insert at any position in the list.
iii) Deleting a node based on specific value.
iv) Displaying all the nodes in the list.
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
NODE* searchkey(NODE *, int);
NODE* i_pos(NODE *, int,int);
NODE* deletekey(NODE *, int);
void display(NODE *);

void main()
{
    NODE *start=NULL;
    int num,choice,k,p;
    while(1)
    {
        printf("Enter your choice\n");
        printf("1. Insert at front\n");
        printf("2. Insert at position\n");
        printf("3. Delete a node\n");
        printf("4. Searching a key\n");
        printf("5. Display\n");
        printf("6. Stop\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf(" Enter data to insert\n");
                    scanf("%d",&num);
                    start= insertfront(start,num);
                    break;
            case 2: printf(" Enter data to insert\n");
                    scanf("%d",&num);
                    printf("Enter position\n");
                    scanf("%d",&p);
                    start= i_pos(start,num,p);
                    break;
            case 3: printf(" Enter the key value");
                    scanf("%d",&k);
                    start= deletekey(start,k);
                    break;
            case 4: printf(" Enter key to be searched\n");
                    scanf("%d",&k);
                    start= searchkey(start,k);
                    break;
            case 5: display(start);
                    break;
            case 6: exit(0);
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

NODE* i_pos(NODE *start, int n, int position)
{
    NODE *new_node, *temp, *ptr;
    int count;
    new_node = (NODE *) malloc(sizeof(struct node));
    new_node -> data = n;
    if ((start == NULL) && (position ==1))
    {
        new_node->next =NULL;
        start = new_node;
    }
    else if ((start == NULL) && (position >1))
    {
        printf("Invalid postion\n");
    }
    else
    {
        count =1;
        ptr = start;
        while((ptr != NULL) && (count !=position))
        {
            temp = ptr;
            ptr= ptr ->next;
            count++;
        }
        if(ptr == NULL)
        {
            printf("Invalid postion\n");
        }
        else
        {
            new_node -> next = ptr;
            temp -> next = new_node;
        }
    }
    return start;
}

NODE* deletekey(NODE *start, int key)
{
    NODE *temp, *ptr;
    if (start == NULL) // No Nodes
    {
        printf("List Empty\n");
    }
    else if (start->data==key ) //first node is key
    {
        printf("Item Deleted: %d\n", start->data);
        ptr=start;
        start = start->next;
        free(ptr);
    }
    else
    {// Traverse till key is found or till last node
        ptr=start;
        while((ptr != NULL)&&(ptr->data !=key))
        {
            temp=ptr;
            ptr = ptr->next;
        }
        if(ptr == NULL) // Searched till end of list
            printf("Invalid key\n");
        else
        {
            temp->next = ptr->next;
            printf("Item deleted: %d\n",ptr->data);
            free(ptr);
        }
    }
    return start;
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

NODE* searchkey(NODE *start, int key)
{
    NODE *ptr;
    if (start == NULL)
    {
        printf("List Empty\n");
    }
    else
    { // Traverse till key is found or till last node
        ptr = start;
        while((ptr != NULL)&&(ptr->data!=key))
        {
            ptr = ptr->next;
        }
        if(ptr == NULL) // Searched till end of list
        {
            printf("Invalid key\n");
        }
        else
        {
            printf("Key %d found \n", ptr->data);
        }
    }
    return start;
}

/*
Sample Output:
Enter your choice
1. Insert at front
2. Insert at position
3. Delete a node
4. Searching a key
5. Display
6. Stop
1
Enter data to insert
11
Enter your choice
1. Insert at front
2. Insert at position
3. Delete a node
4. Searching a key
5. Display
6. Stop
5
The list data are
11
Enter your choice
1. Insert at front
2. Insert at position
3. Delete a node
4. Searching a key
5. Display
6. Stop
6
*/