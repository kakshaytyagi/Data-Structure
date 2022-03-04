//multistack.c
//two stack in single array

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX], Topa = -1, Topb = MAX;

void menU()
{
    printf("\n****MENU****");
    printf("\n 1. Push in stack A");
    printf("\n 2. Push in stack B");
    printf("\n 3. Pop in stack A");
    printf("\n 4. Pop in stack B");
    printf("\n 5. Display Stck A");
    printf("\n 6. Display Stck B");
    printf("\n 7. EXIT");
}

void pushA(int val)
{
    if(Topa == Topb -1)
        printf("\nStack A Overflow");
    else
    {
        Topa++;
        stack[Topa] = val;
    }
    
}
void pushB(int val)
{
    if(Topb - 1 == Topa)
        printf("\nStack B Overflow");
    else
    {
        Topb--;
        stack[Topb] = val;
    }
    
}

int popA()
{
    int val;
    if(Topa == -1)
        printf("\nStack A Underflow");
    else
    {
        val = stack[Topa];
        Topa--;
    }
    return val;
}
int popB()
{
    int val;
    if(Topb == MAX)
        printf("\nStack B Underflow");
    else
    {
        val = stack[Topb];
        Topb++;
    }
    return val;
}

void DisplayA()
{
    int i;
    if (Topa == -1)
        printf("\n Stack A is empty");
    else
    {
        for (i = 0; i <= Topa; i++)
            printf(" %d ", stack[i]);
    }
}
void DisplayB()
{
    int i;
    if (Topb == MAX - 1)
        printf("\n Stack B is empty");
    else
    {
        for (i = MAX - 1; i >= Topb; i--)
            printf(" %d ", stack[i]);
    }
}

int main()
{
    int option, val;

    menU();
    do
    {
        printf("\nEnter the choice: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: printf("\nEnter the value you want to push into the stack A: ");
                    scanf("%d", &val);
                    pushA(val);
                    break;
            case 2: printf("\nEnter the value you want to push into the stack B: ");
                    scanf("%d", &val);
                    pushB(val);
                    break;
            case 3: val = popA();
                    printf("\nValue pop from Stack A: %d", val);
                    break;
            case 4: val = popB();
                    printf("\nValue pop from Stack B: %d", val);
                    break;
            case 5: printf("\n Display the value in stack A: ");
                    DisplayA();
                    break;
            case 6: printf("\n Display the value in stack B: ");
                    DisplayB();
                    break;
        }
    } while (option != 7);
    return 0;
}
