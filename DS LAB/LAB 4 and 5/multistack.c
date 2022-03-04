//multistack.c
//write a program to implement 2 stack array

#include<stdio.h>
#include<conio.h>
#define MAX 10

int TOPA = -1, TOPB = MAX;   
int stack[MAX]; 

void pushA(int val)
{
    if(TOPA == TOPB - 1)
    {
        printf("\nStack is overflow");
    }
    else
    {
        TOPA++;
        stack[TOPA] = val;
        
        printf("\n%d", stack[TOPA]);
    }
}

void popA()
{
    if(TOPA == -1)
    {
        printf("\nStack is underflow");
    }
    else
    {
        int val = stack[TOPA];
        TOPA--;
    }
}

void pushB(int val)
{
    if(TOPB - 1 == TOPA)
    {
        printf("\nStack is overflow");
    }
    else
    {
        TOPB--;
        stack[TOPB] = val;
        printf("\n%d", stack[TOPB]);
    }
}
void popB()
{
    if(TOPB == MAX)
    {
        printf("\nStack is underflow");
    }
    else
    {
        int val = stack[TOPB];
        TOPB++;
    }
}

int main()
{
    pushA(10);
    //pushA(10);
    pushA(10);
    pushA(10);
    popA();
    popA();
    popA();
    popA();
    popA();
    pushA(10);
    pushA(10);
    pushB(5);
    pushB(5);
    pushB(5);
    popB();
    popB();
    popB();
    popB();
    popB();
    popB();
    popB();
    pushB(5);
    pushB(5);
    return 0;
}