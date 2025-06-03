/* Question 6a) Write a C program to convert an expression given in "infix" form to "postfix" using stack concept. */

#include<stdio.h>
#include<ctype.h>
void infixtopostfix(char in[50]);
int precedence(char op);
int main()
{
    char infix[50];
    printf("Enter the expression:");
    scanf("%s",infix);
    infixtopostfix(infix);
    return 0;
}
int precedence(char op)
{
    if(op=='^')
        return 2;
    else if(op=='/' || op == '*' || op=='%')
        return 1;
    else if(op=='+'||op=='-')
        return 0;
}
void infixtopostfix(char in[50])
{
    char stack[50],postfix[50];
    int top=-1,i,j;
    for(i=0,j=0;in[i]!='\0';i++)
    {
        if (isalnum(in[i]))
        {
            postfix[j++] = in[i];
        }
        else if (in[i] == '(' )
        {
            stack[++top] = in[i];
        }
        else if ( in[i] == ')' )
        {
            while (top > -1 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else if(in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/'||in[i]=='%'||in[i]=='^')
        {
            while ((top>-1)&&(precedence(stack[top])>=precedence(in[i])))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = in[i];
        }
    }
    while (top > -1)
    {
        if (stack[top] == '(')
        {
            printf("Invalid Exp");
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    printf("The corresponding postfix expression is:");
    printf("%s",postfix);
}

/* OUTPUT:
Enter any infix expression : (A+B)*C/D+E^F/G
The corresponding postfix expression is : AB+C*D/EF^G/+
*/