//circularqueue.c
//demonstrate the example of circular queue

#include <stdio.h>
#include <curses.h>
#define MAX 10

int queue[MAX];
int FRONT = -1, REAR = -1;

////////////////////////////////////////////////////////////////////////
void queuemenu()
{
    printf("\n 1. For EnQueue operation");
    printf("\n 2. For DeQueue operation");
    printf("\n 3. For Display operation");
    printf("\n 4. For Peek operation");
    printf("\n 5. Exit");
}
////////////////////////////////////////////////////////////////////////
void Enqueue(int val)
{
    if (FRONT == 0 && REAR == MAX - 1)
        printf("\nQueue Overflow\n");
    else if (FRONT == -1 && REAR == -1)
        FRONT = REAR = 0;
    else if (REAR == MAX - 1 && FRONT != 0)
        REAR = 0;
    else
        REAR = REAR + 1;

    queue[REAR] = val;
}
////////////////////////////////////////////////////////////////////////
int Dequeue()
{
    int val;
    if (FRONT == -1)
    {
        printf("\nQueue Underflow\n");
        return -1;
    }
    val = queue[FRONT];
    if (FRONT == REAR)
        FRONT = REAR = -1;
    else if (FRONT == MAX - 1)
        FRONT = 0;
    else
        FRONT = FRONT + 1;

    return val;
}
////////////////////////////////////////////////////////////////////////
void Display()
{
    if (FRONT == -1 && REAR == -1)
        printf("\nQueue is Empty\n");
    else
    {
        if (FRONT < REAR)
        {
            for (int i = FRONT; i <= REAR; i++)
                printf(" %d ", queue[i]);
        }
        else
        {
            for (int i = FRONT; i < MAX; i++)
                printf(" %d ", queue[i]);
            for (int i = 0; i <= REAR; i++)
                printf(" %d ", queue[i]);
        }
    }
}
////////////////////////////////////////////////////////////////////////
int peek()
{
    if (FRONT == -1 && REAR == -1)
        printf("\nQueue is Empty\n");
    else 
        return queue[FRONT];
    return -1;
}
////////////////////////////////////////////////////////////////////////
int main()
{
    int option, val;
    queuemenu();
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: printf("\nEnter the value to queue: ");
                    scanf("%d", &val);
                    Enqueue(val);
                    break;

            case 2: val = Dequeue();
                    printf("value to be dequeue from the queue: %d", val);
                    break;

            case 3: printf("Queue: ");
                    Display();
                    break;

            case 4: val = peek();
                    printf("\nValue at the Front: %d", val);
                    break;

        }
    } while (option != 5);
    return 0;   
}
///////////////////////////////////////////////////////////////////////////////