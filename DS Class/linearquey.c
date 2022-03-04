//linearquey.c
//using linear quey

#include<stdio.h>
#define MAX 5
int front = 0, rear = -1, queue[MAX];

int peek()
{
    return queue[front];
}

int isfull()
{
    if (rear = MAX -1)
        return 1;
        else 
        return 0;
}
int isEmpty()
{
    if (front = -1 || rear = MAX -1)
        return 1;
        else 
        return 0;
}

void enqueue(int val)
{
    if (isfull() == 1)
        printf("\n Overflow");
    else
    {
        rear++;
        queue[rear] = val;
    }
}

void dequeue()
{
    if (isEmpty() == 1)
        printf("\n UNderflow");
    else
        front++;
}

void display()
{
    int i;
    printf("\nFront  = %d, Rear = %d ", front , rear);
    printf("\n Queue Value = ");
    for (i = front; i <= rear; i++)
        printf("%d", queue[i]);
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();
    dequeue();
    display();
    return 0;



}