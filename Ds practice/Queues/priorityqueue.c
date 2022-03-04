//priorityqueue.c
//program for proiority Queue

#include <stdio.h>
#include <curses.h>
#define MAX 10

int rear = -1, front = -1;

struct queue
{
    int data;
    int priority;
} queue[MAX];
///////////////////////////////////////////////////////////////////////////////////
void queuemenu()
{
    printf("\n 1. For EnQueue operation");
    printf("\n 2. For DeQueue operation");
    printf("\n 3. For Display operation");
    printf("\n 4. For Peek operation");
    printf("\n 5. Exit");
}
///////////////////////////////////////////////////////////////////////////////////
void Enqueue()
{
    if (front == 0 && rear == MAX - 1)
        printf("\nQueue Overflow");
    if (front == -1 && rear == -1)
        front = rear = 0;
    else if (front != 0 && rear == MAX - 1)
        rear = 0;
    else
        rear++;
    printf("\nEnter the data and its priorty: ");
    scanf("%d", &queue[rear].data);
    scanf("%d", &queue[rear].priority);
}
///////////////////////////////////////////////////////////////////////////////////
int priority()
{
    int p = -1, i = 0, val;
    if (front == -1)
        printf("\nQueue is Empty");
    while (queue[i].priority >= p)
    {
        p = queue[i].priority;
        i++;
    }
    val = queue[i].data;
    queue[i].data = 0;
    queue[i].priority = -1;
    return val;
}
///////////////////////////////////////////////////////////////////////////////////
int Dequeue()
{
    int val;
    if (front == -1)
    {
        printf("\nQueue Underflow");
        return -1;
    }
    val = priority();
    if (front == rear)
        front = rear = -1;
    else if (front = MAX - 1)
        front = 0;
    return val;
}

///////////////////////////////////////////////////////////////////////////////////
void Display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("\t %d", queue[i].data);
    }
}
///////////////////////////////////////////////////////////////////////////////////
int main()
{
    int option, val;
    queuemenu();
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter the value to queue: ");
            Enqueue();
            break;

        case 2:
            val = Dequeue();
            printf("value to be dequeue from the queue: %d", val);
            break;

        case 3:
            printf("Queue: ");
            Display();
            break;


        }
    } while (option != 5);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////
