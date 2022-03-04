// peekstack.c
// using peek operation in stack

#include <stdio.h>
#include <conio.h> // console input output
#define MAX 5      // define MAX = 5

int TOP = 2;                   // SET TOP =2
int stack[MAX] = {10, 20, 30}; // declare stack globally
int peek()                     // called function  || function defination
{
    if (TOP < 0)                    // IF TOP < 0
        printf("STACK IS EMPTY\n"); // then PRINT "EMPTY"
    else                            // otherwise
    {
        int val = stack[TOP]; // SET val = stack[TOP]
        TOP -= 1;             // SET TOP = TOP -1
        return val;           // return top value
    }
}

int main()
{
    int getval;
    getval = peek(); // calling funciton
    printf("%d ", getval);
    getval = peek(); //
    printf("%d ", getval);
    getval = peek(); //
    printf("%d ", getval);
    getval = peek(); //
    printf("%d ", getval);
    getval = peek(); //
    printf("%d ", getval);
    return 0;
}