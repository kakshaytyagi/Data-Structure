//stackusingarry.c
// Write a program to implement stack using arrays.

#include<stdio.h>
#include<conio.h>
#define MAX 10

int TOP = -1; //SET TOP = -1 i.e Empty stack condition
int stack[MAX];

//===================================== *push* ===========================================
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
//======================================= *END POP* ===========================================

//======================================== *POP* ========================================
void pop()
{
    if (TOP == 0)                     // IF TOP = 0
        printf("STACK IS UNDERFLOW"); // then PRINT "UNDERFLOW"
    else
    {
        int val = stack[TOP]; // SET val = stack[TOP]
        TOP -= 1;             // SET TOP = TOP - 1
    }
}
//============================================ *POP END* =======================================

//============================================ *PEEK* ================================
int peek()                     // called function  || function defination
{
    int val;
    if (TOP < 0)                    // IF TOP < 0
        printf("STACK IS EMPTY\n"); // then PRINT "EMPTY"
    else                            // otherwise
    {
        val = stack[TOP]; // SET val = stack[TOP]
        TOP -= 1;             // SET TOP = TOP -1
    }
    return val;
}
//========================================== *PEEK END* ====================================

//------------------------------ *MAIN BODY* ------------------------------------------------
int main()
{
    int getval;
    push(10); // calling funciton with argument 
    push(20); //
    push(30); //
    push(40); //

    pop(); // calling function
    printf("\n");
    for (int i = 0; i <= TOP; i++) // after 1st element pop out
        printf(" %d ", stack[i]);

    pop(); // calling function
    printf("\n");
    for (int i = 0; i <= TOP; i++) // after 2st element pop out
        printf(" %d ", stack[i]);

    getval = peek(); // calling funciton
    printf("\n%d ", getval);
    return 0;
}
//--------------------------------------------------------------------------------------


