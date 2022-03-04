//priorityque.c
//Write a menu driven program to implement following operations on Priority Queue:​
//-enQueue()​
//-deQueue()​
//-display()

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#define MAX 10
int temp;
int rear = -1, front = -1;
struct que
{
    int data;
    int priority;
}queue[MAX];

void queuemenu()
{
    printf("\n 1. For EnQueue operation");
    printf("\n 2. For DeQueue operation");
    printf("\n 3. For Display operation");
    printf("\n 4. Exit");
}
///////////////////////////////////////////////////////////////////////////////////
void Enqueue()
{
    if (front == 0 && rear == MAX - 1)
        printf("Queue Overflow");
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else if (front != 0 && rear == MAX - 1)
        rear = 0;
    else 
        rear++;
    printf("\nEnter the data and its priority: ");
    scanf("%d", &queue[rear].data);
    scanf("%d", &queue[rear].priority);
}
///////////////////////////////////////////////////////////////////////////////////
int priority()
{
    int p = -1, start;
    temp = 0;
    start = front;
    while (start <= rear) // 0, 1, 2, 3, 4(exit)
    {
        if (queue[start].priority > p) //3>-1, 2>3, 1>3, 4>3
        {
            p = queue[start].priority;  //3,4
            temp = start;   //0,3
        }
        start++; //1, 2, 3, 4
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////
int Dequeue()
{
    int val;
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    priority();
    val = queue[temp].data;
    queue[temp].priority = -1;
    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
    {
        if (temp == rear)
            rear--;
        else
        {
            for (int i = temp; i <= rear; i++)
            {
                queue[i].data = queue[i + 1].data;
                queue[i].priority = queue[i + 1].priority;
            }
            rear--;
        } 
    }
    return val;
}
///////////////////////////////////////////////////////////////////////////////////
void Display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d (%d priority)", queue[i].data, queue[i].priority);
        printf("\n");
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
            Enqueue();
            break;

        case 2:
            val = Dequeue();
            printf("value to be dequeue from the queue: %d", val);
            break;

        case 3:
            printf("Queue: \n");
            Display();
            break;
        }
    } while (option != 4);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////
