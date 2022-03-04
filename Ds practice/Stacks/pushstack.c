//pushstack.c
//using push operation in stack

#include <stdio.h>
#include <conio.h> // console input output
#define MAX 4

int TOP = -1; //SET TOP = -1 i.e Empty stack condition
int stack[MAX];

void push(int Val) // called funciton of push
{
    if (TOP == MAX - 1) // IF TOP = MAX - 1 then print "OVERFLOW" goto main function
    {
        printf("Stack is overflow");
    }
    else
    {
        TOP += 1;                   // else TOP++
        stack[TOP] = Val;           // INPUT value at TOP of the stack
        printf(" %d ", stack[TOP]); // print "STACK"
    }
}

int main()
{
    push(10); // calling funciton with argument 
    push(20); //
    push(30); //
    push(40); //
    push(50); //At this STACK is "OVERFLOW"
    return 0;
}