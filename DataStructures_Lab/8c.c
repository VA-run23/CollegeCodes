// 8c) Write a C program to print all root to leaf paths of a Binary Search Tree (BST).

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *insertnode(NODE *, int);
void printPathsRecur(NODE *root, int path[], int pathlen);

int main() {
    int option, val, pathlen, path[100];
    NODE *root = NULL;

    while (1) {
        printf("\n 1. Insert Element");
        printf("\n 2. Print path");
        printf("\n 3. Exit");
        printf("\nEnter your option :\n ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n Enter Value : ");
                scanf("%d", &val);
                root = insertnode(root, val);
                break;
            case 2:
                printPathsRecur(root, path, 0);
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}

NODE *insertnode(NODE *root, int val) {
    NODE *new_node, *ptr, *temp;
    new_node = (NODE *)malloc(sizeof(NODE));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL) {
        root = new_node;
    } else {
        ptr = root;
        while (ptr != NULL) {
            temp = ptr;
            if (val < ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if (val < temp->data)
            temp->left = new_node;
        else
            temp->right = new_node;
    }
    return root;
}

void printPathsRecur(NODE *root, int path[], int pathlen) {
    if (root == NULL) 
        return;

    path[pathlen] = root->data;
    pathlen++;

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < pathlen; i++)
            printf("%d ", path[i]);
        printf("\n");
    } else {
        printPathsRecur(root->left, path, pathlen);
        printPathsRecur(root->right, path, pathlen);
    }
}


// Sample Output:
// 1. Insert Element
// 2. Print path
// 3. Exit
// Enter your option: 1
// Enter Value: 12
// Enter your option: 1
// Enter Value: 6
// Enter your option: 1
// Enter Value: 23
// Enter your option: 1
// Enter Value: 48
// Enter your option: 1
// Enter Value: 1
// Enter your option: 1
// Enter Value: 8
// Enter your option: 2
// Root to Leaf Paths:
// 12 6 1  
// 12 6 8  
// 12 23 48  
// Enter your option: 3
