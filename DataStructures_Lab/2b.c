/*
Question 2.b) Write a C program to read and display the student details. Define a structure 'Student' 
with fields name (string), usn (int), marks of 3 subjects (int) and average (float) in it. Store the 
details of n students in an array of structure 'Student'. Display the details of all students in the 
descending order their total marks.
*/

#include<stdio.h>

struct student
{
    char name[20];
    int usn;
    int m1,m2,m3;
    float avg;
};

int main()
{
    struct student s[20];
    int n,total=0;
    printf("Enter the number of students:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the name:\n");
        scanf("%s",s[i].name);
        printf("Enter the USN :\n");
        scanf("%d",&s[i].usn);
        printf("Enter the 3 subject marks:\n");
        scanf("%d%d%d",&s[i].m1,&s[i].m2,&s[i].m3);
        total=s[i].m1+s[i].m2+s[i].m3;
        s[i].avg=total/3.0;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[i].avg<s[j].avg)
            {
                struct student temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    
    printf("\t*Students Deatails in descending order*\n");
    for(int i=0;i<n;i++)
    {
        printf("\nStudent's USN = %d", s[i].usn);
        printf("\nStudent's Name = %s", s[i].name);
        printf("\nStudent's average Marks = %.2f", s[i].avg);
        printf("\n");
    }
    return 0;
}

/*
Output:
Enter the number of students:
3
Enter the name:
abc
Enter the USN :
1
Enter the 3 subject marks:
67
55
70
Enter the name:
xyz
Enter the USN :
2
Enter the 3 subject marks:
40
38
45
Enter the name:
pqr
Enter the USN :
3
Enter the 3 subject marks:
90
99
98
*Students Deatails in descending order*

Student's USN = 3
Student's Name = pqr
Student's average Marks = 95.67

Student's USN = 1
Student's Name = abc
Student's average Marks = 64.00

Student's USN = 2
Student's Name = xyz
Student's average Marks = 41.00
*/