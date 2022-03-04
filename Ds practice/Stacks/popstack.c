//popstack.c
// demonistrate the pop operation using stack

#include <stdio.h>
#include <conio.h> // console input output
#define MAX 6      // SET MAX = 6

int TOP = 3;                   // SET TOP = 3
int stack[MAX] = {10, 20, 30}; // stack with initalization

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

int main()
{
    for (int i = 0; i < TOP; i++) // PRINT orignal stack
        printf(" %d ", stack[i]);
    pop(); // calling function
    printf("\n");
    for (int i = 0; i < TOP; i++) // after 1st element pop out
        printf(" %d ", stack[i]);
    pop(); //
    printf("\n");
    for (int i = 0; i < TOP; i++) // after 2nd
        printf(" %d ", stack[i]);
    pop(); //
    printf("\n");
    for (int i = 0; i < TOP; i++)
        printf(" %d ", stack[i]);

    pop();
    printf("\n");
    for (int i = 0; i < TOP; i++)
        printf(" %d ", stack[i]);

    pop();
    printf("\n");
    for (int i = 0; i < TOP; i++)
        printf(" %d ", stack[i]);

    pop();
    printf("\n");
    for (int i = 0; i < TOP; i++)
        printf(" %d ", stack[i]);
    pop();
    printf("\n");
    for (int i = 0; i < TOP; i++)
        printf(" %d ", stack[i]);

    return 0;
}