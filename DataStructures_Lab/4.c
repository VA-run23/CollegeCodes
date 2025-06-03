/*
Question 4. Write a C program to support the following operations on a doubly linked list where each
node consists of integers.
i) Create a doubly linked list by adding each node at the front.
ii) Insert a new node to the left of the node whose key value is read as input.
iii) Delete the node of a given data, if it is found, otherwise display appropriate message.
iv) Display the contents of the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *leftlink;
    int data;
    struct node *rlink;
};
typedef struct node NODE;

NODE* insertfront(NODE *, int);
NODE* i_beforekey(NODE *, int,int);
NODE* deletekey(NODE *, int);
void display(NODE *);

void main()
{
    NODE *start=NULL;
    int num,choice,k;
    while(1)
    {
        printf("\nEnter your choice\n");
        printf("1. Insert at front\n");
        printf("2. Insert before data\n");
        printf("3. Delete a key node\n");
        printf("4. Display\n");
        printf("5. Stop\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf(" Enter data to insert\n");
                    scanf("%d",&num);
                    start= insertfront(start,num);
                    break;
            case 2: printf(" Enter data to insert\n");
                    scanf("%d",&num);
                    printf("Enter key before which to insert\n");
                    scanf("%d",&k);
                    start= i_beforekey(start,num,k);
                    break;
            case 3: printf(" Enter the key value");
                    scanf("%d",&k);
                    start= deletekey(start,k);
                    break;
            case 4: display(start);
                    break;
            case 5: exit(0);
        }
    }
}

void display(NODE *start)
{
    NODE *ptr;
    ptr = start;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("The list data are \n");
        while(ptr != NULL)
        {
            printf("->%d ", ptr->data);
            ptr = ptr->rlink;
        }
    }
}

NODE* insertfront(NODE *start, int n)
{
    NODE *new_node;
    new_node = (NODE *)malloc(sizeof(struct node));
    new_node ->data = n;
    new_node ->leftlink=NULL;
    new_node ->rlink=NULL;
    if(start==NULL)
    {
        start=new_node;
    }
    else
    {
        new_node ->rlink = start;
        start->leftlink= new_node;
        start = new_node;
    }
    return start;
}

NODE* i_beforekey(NODE *start, int n, int key)
{
    NODE * new_node , * temp, * ptr;
    new_node = (NODE *) malloc(sizeof(struct node));
    new_node ->data = n;
    if (start== NULL)
    {
        printf("List Empty, cannot insert\n");
    }
    else if(start ->data==key ) // if start node is the key
    {
        new_node ->rlink = start;
        start ->leftlink = new_node ;
        new_node->leftlink = NULL;
        start = new_node ;
    }
    else
    { // Traverse till key is found or till last node
        ptr= start;
        while((ptr != NULL) && (ptr->data!=key))
        {
            temp = ptr;
            ptr = ptr->rlink;
        }
        if(ptr == NULL) // Searched till end of list
            printf("Invalid key\n");
        else
        {
            new_node ->rlink = ptr;
            ptr->leftlink = new_node ;
            new_node ->leftlink = temp;
            temp->rlink = new_node ;
        }
    }
    return start;
}

NODE* deletekey(NODE *start, int key)
{
    NODE *ptr, *temp;
    if (start == NULL) // No Nodes
    {
        printf("List Empty\n");
    }
    else if(start->data==key ) //first node is key
    {
        ptr=start;
        start = start->rlink;
        printf("Item Deleted: %d\n", ptr->data);
        free(ptr);
    }
    else
    {
        ptr=start;
        while((ptr!= NULL)&&(ptr->data!=key))
        {
            temp=ptr;
            ptr= ptr->rlink;
        }
        if(ptr == NULL) // Searched till end of list
            printf("Invalid key number\n");
        else
        {
            temp->rlink = ptr->rlink;
            if(ptr->rlink !=NULL)
                (ptr->rlink)->leftlink = temp;
            printf("Item deleted: %d\n",ptr->data);
            free(ptr);
        }
    }
    return start;
}

/*
Output:
Enter your choice
1. Insert at front
2. Insert before data
3. Delete a key node
4. Display
5. Stop
1
Enter data to insert
11

Enter your choice
1. Insert at front
2. Insert before data
3. Delete a key node
4. Display
5. Stop
1
Enter data to insert
22

Enter your choice
1. Insert at front
2. Insert before data
3. Delete a key node
4. Display
5. Stop
1
Enter data to insert
33

Enter your choice
1. Insert at front
2. Insert before data
3. Delete a key node
4. Display
5. Stop
4
The list data are
->33 ->22 ->11

Enter your choice
1. Insert at front
2. Insert before data
3. Delete a key node
4. Display
5. Stop
2
Enter data to insert
55
Enter key before which to insert
22

Enter your choice
1. Insert at front
2. Insert before data
3. Delete a key node
4. Display
5. Stop
4
The list data are
->33 ->55 ->22 ->11

Enter your choice
1. Insert at front
2. Insert before data
3. Delete a key node
4. Display
5. Stop
3
Enter the key value33
Item Deleted: 33

Enter your choice
1. Insert at front
2. Insert before data
3. Delete a key node
4. Display
5. Stop
4
The list data are
->55 ->22 ->11

Enter your choice
1. Insert at front
2. Insert before data
3. Delete a key node
4. Display
5. Stop
5
*/