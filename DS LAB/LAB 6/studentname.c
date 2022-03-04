//studentname.c
//WAP to implement a stack that stores names of students of a class. Perform all operations. i.e PUSH, POP, Display

#include<stdio.h>

#include<string.h>
#define MAX 50


//========================================== *PEEK END* ====================================
int main()
{
    int N; 
    char arr[MAX];
    printf("\nEnter the no. of students are: ");
    scanf("%d", &N);
    while(N--)
    {
        printf("\nEnter the Student name: ");
        gets(arr);
    }
    while(N--)
    {
        puts(arr);
    }
    return 0;
}