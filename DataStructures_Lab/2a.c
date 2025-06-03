/*
Question 2.a) Write a C program to read and display the Time in specified format. Create a structure 
called Time with hour (int), minute (int), second (int) and next(self-referencing pointer) as its 
members. Dynamically create two variables of structure TIME and link the first variable to the 
second one and display it. Write a Display function that takes address of first TIME variable 
and displays both times in the format h:m:s.
*/

#include <stdio.h>
#include<stdlib.h>

struct time
{
    int h,m,s;
    struct time *next;
};

void display(struct time *);

int main()
{
    struct time *t1,*t2;
    t1=malloc(sizeof(struct time));
    printf("Enter the hour,minute and second for time1\n");
    scanf("%d%d%d",&t1->h,&t1->m,&t1->s);
    t2=malloc(sizeof(struct time));
    printf("Enter the hour,minute and second for time2\n");
    scanf("%d%d%d",&t2->h,&t2->m,&t2->s);
    t1->next=t2;
    display(t1);
    return 0;
}

void display(struct time *t)
{
    struct time *temp=t;
    printf("%d:%d:%d\n",temp->h,temp->m,temp->s);
    temp=temp->next;
    printf("%d:%d:%d",temp->h,temp->m,temp->s);
}

/*
Output:
Enter the hour,minute and second for time1
1
30
20
Enter the hour,minute and second for time2
2
5
60
1:30:20
2:5:60
*/