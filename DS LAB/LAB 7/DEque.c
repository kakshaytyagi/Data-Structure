//DEque.c
//Write a menu driven program to implement following operations on Double Ended Queue:​
//-enQueue() [at front/rear]​
//-deQueue() [at front/rear]​
//-display()​

#include <stdio.h>
#include <curses.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;
////////////////////////////////////////////////////////////////////////////////////////
void queuemenu()
{
    printf("\n For EnQueue operation\n");
    printf("\t\t 1. Enqueue from Right\n");
    printf("\t\t 2. Enqueue from left");
    printf("\n For DeQueue operation\n");
    printf("\t\t 3. Dequeue from Right\n");
    printf("\t\t 4. Dequeue from left");
    printf("\n 5. For Display operation");
    printf("\n 6. Exit");
}
////////////////////////////////////////////////////////////////////////////////////////
void EnqueueR(int val)
{
    if (front == 0 && rear == MAX - 1)
        printf("\nQueue Overflow\n");
    if (front == -1 && rear == -1)
        front = rear = 0;
    else if (front != 0 && rear == MAX - 1)
        rear = 0;
    else
        rear = rear + 1;
    queue[rear] = val;
}
////////////////////////////////////////////////////////////////////////////////////////
void EnqueueL(int val)
{
    if (front == 0 && rear == MAX - 1)
        printf("\nQueue Overflow\n");
    if (front == -1 && rear == -1)
        front = rear = 0;
    else if (rear != MAX -1 && front == 0)
        front = (MAX - 1);
    else
        front = front - 1;
    queue[front] = val;
}
////////////////////////////////////////////////////////////////////////////////////////
int DequeueL()
{
    int val;
    if (front == -1)
    {
        printf("\nQueue Underflow\n");
        return -1;
    }
    val = queue[front];
    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front = front + 1;
    return val;
}
////////////////////////////////////////////////////////////////////////////////////////
int DequeueR()
{
    int val;
    if (front == -1)
    {
        printf("\nQueue Underflow\n");
        return -1;
    }
    val = queue[rear];
    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear = rear - 1;
    return val;
}
////////////////////////////////////////////////////////////////////////////////////////
void Display()
{
    if (front == -1 && rear == -1)
        printf("\nQueue is Empty\n");
    else
    {
        if (front < rear)
        {
            for (int i = front; i <= rear; i++)
                printf(" %d ", queue[i]);
        }
        else
        {
            for (int i = front; i < MAX; i++)
                printf(" %d ", queue[i]);
            for (int i = 0; i <= rear; i++)
                printf(" %d ", queue[i]);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////
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
        case 1: printf("\nEnter the value for Enqueue at right: ");
                scanf("%d", &val);
                EnqueueR(val);
            break;

        case 2: printf("\nEnter the value for Enqueue at left: ");
                scanf("%d", &val);
                EnqueueL(val);
            break;

        case 3: val = DequeueR();
                printf("\nDequeue from the right: %d", val);
            break;

        case 4: val = DequeueL();
                printf("\nDequeue from the right: %d", val);
            break;

        case 5: printf("\nQueue : ");
                Display();
            break;

        }
    } while (option != 6);
    return 0;
}