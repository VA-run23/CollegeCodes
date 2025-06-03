/* Question 8a) Write a C program to construct a binary tree of integers and also display elements in the tree using Inorder, Preorder and Postorder traversals. */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node *insertnode(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
int main()
{
    int option, val;
    struct node *root=NULL;
    while(1)
    {
        printf("\n 1. Insert Element");
        printf("\n 2. Preorder Traversal");
        printf("\n 3. Inorder Traversal");
        printf("\n 4. Postorder Traversal");
        printf("\n 5. Exit");
        printf("\nEnter your option :\n ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: printf("\n Enter Value : ");
                    scanf("%d", &val);
                    root = insertnode(root, val);
                    break;
            case 2:
                    printf("\nPre-order Traversal: \n");
                    preorderTraversal(root);
                    break;
            case 3:
                    printf("\nIn-order Traversal : \n");
                    inorderTraversal(root);
                    break;
            case 4:
                    printf("\nPost-order Traversal : \n");
                    postorderTraversal(root);
                    break;
            case 5:
                    exit(0);
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
void preorderTraversal(struct node *root)
{
    if(root != NULL)
    {
        printf("%d\t", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(struct node *root)
{
    if(root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\t", root->data);
    }
}
void inorderTraversal(struct node *root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d\t", root->data);
        inorderTraversal(root->right);
    }
}

/* OUTPUT:
1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
1
Enter Value : 20

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
1
Enter Value : 4

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
1
Enter Value : 14

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
1
Enter Value : 30

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
1
Enter Value : 29

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
1
Enter Value : 52

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
1
Enter Value : 6

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
1
Enter Value : 7

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
1
Enter Value : 9

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
2
Pre-order Traversal:
20 4 14 6 7 9 30 29 52

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
3
In-order Traversal :
4 6 7 9 14 20 29 30 52

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :
4
Post-order Traversal :
9 7 6 14 4 29 52 30 20

1. Insert Element
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your option :5
*/