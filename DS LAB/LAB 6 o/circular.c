//circular.c
//Write a menu driven program to implement following operations on Circular Queue:​
// -enQueue()​
// -deQueue()​
// -display()

#include <stdio.h>
#include <curses.h>
#define MAX 10

int queue[MAX];
int FRONT = -1, REAR = -1;

//-----------------------------------------------------------------------------
void queuemenu()
{
    printf("\n 1. For EnQueue operation");
    printf("\n 2. For DeQueue operation");
    printf("\n 3. For Display operation");
    printf("\n 4. For Peek operation");
    printf("\n 5. Exit");
}
//-------------------------------------------------------------------------------
void enqueue(int vl)
{
    if (FRONT == 0 && REAR == MAX - 1)
        printf("\nQueue is overflow.\n");
    else if (FRONT == -1 && REAR == -1)
    {
        FRONT = REAR = 0;
        queue[REAR] = vl;
    }
    else if (REAR == MAX - 1 && FRONT != 0)
    {
        REAR = 0;
        queue[REAR] = vl;
    }
    else
    {
        REAR++;
        queue[REAR] = vl;
    }
}
//--------------------------------------------------------------------------------

int dequeue()
{
    int vl;
    if (FRONT == -1 && REAR == -1)
    {
        printf("\nQueue is underflow");
        return -1;
    }
    vl = queue[FRONT];
    if (FRONT == REAR)
    {
        FRONT = REAR = -1;
    }
    else
    {
        if (FRONT == MAX - 1)
            FRONT = 0;
        else
            FRONT++;
    }
    return vl;
}

//-------------------------------------------------------------------------
void display()
{
    if (FRONT == -1 && REAR == -1)
        printf("\nQueue is Empty");
    else
    {
        if (FRONT < REAR)
        {
            for (int i = FRONT; i <= REAR; i++)
                printf("\t %d", queue[i]);
        }
        else
        {
            for (int i = FRONT; i < MAX; i++)
                printf("\t %d", queue[i]);
            for (int i = 0; i <= REAR; i++)
                printf("\t %d", queue[i]);
        }
    }
}
//--------------------------------------------------------------------------

int peek()
{
    int vl;
    if (FRONT == -1 && REAR == -1)
    {
        printf("\nQueue is Empty");
        return -1;
    }
    else
    {
        vl = queue[FRONT];
        return vl;
    }
}
//------------------------------------------------------------------------------
int main()
{
    int option, val;

    queuemenu();
    do
    {
        printf("\nEnter the choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter the value for enqueue : ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 2:
            val = dequeue();
            if (val != -1)
                printf("\ndequeue value is : %d\n", val);
            break;
        case 3:
            display();
            break;
        case 4:
            val = peek();
            if (val = -1)
                printf("\nPeek value is : %d\n", val);
            break;

        default:
            printf("\nYou entered wrong value.");
            break;
        }
    } while (option != 5);
    return 0;
}
