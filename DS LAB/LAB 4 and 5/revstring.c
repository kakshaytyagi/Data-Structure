// revstring,c
// Write program to reverse a string stack arrays.

#include <stdio.h>
#include <conio.h> // using console input output
#include <string.h>

#define MAX 150

int TOP = -1; //SET TOP = -1 i.e Empty stack condition
char stack[MAX];

//===================================== *push* ===========================================
void push(char Val) // called funciton of push
{
    if (TOP == MAX - 1) // IF TOP = MAX - 1 then print "OVERFLOW" goto main function
    {
        printf("Stack is overflow");
    }
    else
    {
        TOP += 1;                 // else TOP++
        stack[TOP] = Val;         // INPUT value at TOP of the stack
        printf("%c", stack[TOP]); // print "STACK"
    }
}
//======================================= *END POP* ===========================================

//======================================== *POP* ==============================================
int pop()
{
    if (TOP == -1)                      // IF TOP = 0
        printf("\nSTACK IS UNDERFLOW"); // then PRINT "UNDERFLOW"
    else
    {
        char val = stack[TOP]; // SET val = stack[TOP]
        printf("%c", stack[TOP]);
        TOP -= 1; // SET TOP = TOP - 1
    }
    return 0;
}
//============================================ *POP END* =======================================

//=========================================== *MAIN* ===========================================
int main()
{
    char str[MAX], val;
    int i = 0, length;
    printf("Enter the string : ");
    gets(str);
    while (str[i] != '\0')
        i++;

    length = i;
    for (int j = 0; j < length; j++) // SET j = 0 & REPEAT until j < i
    {
        val = str[j]; //SET val = String[j]
        push(val);    //pushing into stack
    }

    printf("\nAfter reversing : ");
    for (int j = 0; j < length; j++) // SET j = 0 & REPEAT until j < i
    {
        pop(); //pop out from the stack
    }
    return 0;
}
//===============================================================================================