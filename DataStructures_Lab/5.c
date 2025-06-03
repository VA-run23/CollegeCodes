/* Question 5. Write a C program to Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX)
i) Push an Element on to Stack
ii) Pop an Element from Stack
iii) Demonstrate Overflow and Underflow situations on Stack
iv) Display the status of Stack
v) Exit
Support the program with appropriate functions for each of the above operations. */

#include<stdio.h>
#include<stdlib.h>
#define max_size 5
int stack[max_size],top=-1;
void push();
void pop();
void display();
int main()
{
    int choice;
    while(1)
    {
        printf("\n\nSTACK OPERATIONS\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("\nEnter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("\nInvalid choice:\n");
                    break;
        }
    }
    return 0;
}
void push() //Inserting element into the stack
{
    int item,n;
    if(top==(max_size-1))
    {
        printf("\nStack Overflow:");
    }
    else
    {
        printf("Enter the element to be inserted:\t");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;
    }
}
void pop() //deleting an element from the stack
{
    int item;
    if(top==-1)
    {
        printf("Stack Underflow:");
    }
    else
    {
        item=stack[top];
        top=top-1;
        printf("\nThe poped element: %d\t",item);
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is Empty:");
    }
    else
    {
        printf("\nThe stack elements are:\n" );
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

/* OUTPUT:
STACK OPERATIONS
1.Push
2.Pop
3.Display
4.Exit
Enter your choice: 1
Enter the element to be inserted: 11

STACK OPERATIONS
1.Push
2.Pop
3.Display
4.Exit
Enter your choice: 1
Enter the element to be inserted: 22

STACK OPERATIONS
1.Push
2.Pop
3.Display
4.Exit
Enter your choice: 1
Enter the element to be inserted: 33

STACK OPERATIONS
1.Push
2.Pop
3.Display
4.Exit
Enter your choice: 3
The stack elements are:
33
22
11

STACK OPERATIONS
1.Push
2.Pop
3.Display
4.Exit
Enter your choice: 2
The poped element: 33

STACK OPERATIONS
1.Push
2.Pop
3.Display
4.Exit
Enter your choice: 3
The stack elements are:
22
11

STACK OPERATIONS
1.Push
2.Pop
3.Display
4.Exit
Enter your choice: 4
*/