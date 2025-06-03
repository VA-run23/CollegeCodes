/* Question 8b) Write a C program to find the number of leaf nodes in a BST */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;
NODE *root;
NODE *insertnode(NODE *, int);
int totalLeafNodes(NODE *);
int main()
{
    int option, val;
    NODE *root=NULL;
    while(1)
    {
        printf("\n 1. Insert Element");
        printf("\n 2. Count Leaf nodes");
        printf("\n 3. Exit");
        printf("\nEnter your option :\n ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:printf("\n Enter Value : ");
                   scanf("%d", &val);
                   root = insertnode(root, val);
                   break;
            case 2: printf("\nTotal leaf node = %d\n",totalLeafNodes(root));
                    break;
            case 3:exit(0);
        }
    }
    return 0;
}
struct node* insertnode(struct node *root, int val)
{
    struct node *new_node, *ptr, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = val;
    new_node ->left = NULL;
    new_node ->right = NULL;
    if(root==NULL)
        root= new_node;
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            temp=ptr;
            if(val < (ptr ->data))
                ptr=ptr ->left;
            else
                ptr = ptr ->right;
        }
        if(val < (temp ->data))
            temp ->left = new_node;
        else
            temp ->right = new_node;
    }
    return root;
}
int totalLeafNodes(NODE *root)
{
    if(root==NULL)
        return 0;
    else if((root->left==NULL) && (root->right==NULL))
    {
        printf("\n%d ", root->data);
        return 1;
    }
    else
        return (totalLeafNodes(root->left) + totalLeafNodes(root->right));
}

/* OUTPUT:
1. Insert Element
2. Count Leaf nodes
3. Exit
Enter your option :
1
Enter Value : 45

1. Insert Element
2. Count Leaf nodes
3. Exit
Enter your option :
1
Enter Value : 39

1. Insert Element
2. Count Leaf nodes
3. Exit
Enter your option :
1
Enter Value : 56

1. Insert Element
2. Count Leaf nodes
3. Exit
Enter your option :
1
Enter Value : 54

1. Insert Element
2. Count Leaf nodes
3. Exit
Enter your option :
1
Enter Value : 55

1. Insert Element
2. Count Leaf nodes
3. Exit
Enter your option :
1
Enter Value : 78

1. Insert Element
2. Count Leaf nodes
3. Exit
Enter your option :
1
Enter Value : 80

1. Insert Element
2. Count Leaf nodes
3. Exit
Enter your option :
2
39
55
80
Total leaf node = 3

1. Insert Element
2. Count Leaf nodes
3. Exit
Enter your option :
3
*/