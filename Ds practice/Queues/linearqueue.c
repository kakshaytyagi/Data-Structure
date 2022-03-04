//linearqueue.c
//write the program to implement a linear queue

#include <stdio.h>
#define MAX 10

int queue[MAX];
int FRONT = -1, REAR = -1;
/////////////////////////////////////////////////////////////////
void queuemenu()
{
    printf("\n 1. For EnQueue operation");
    printf("\n 2. For DeQueue operation");
    printf("\n 3. For Display operation");
    printf("\n 4. For Peek operation");
    printf("\n 5. Exit");
}
/////////////////////////////////////////////////////////////////////////////
void Enqueue(int vl)
{
    if (REAR == MAX - 1)
        printf("\nQueue Overflow\n");
    else if (FRONT == -1 && REAR == -1)
        FRONT = REAR = 0;
    else
    {
        REAR++;
    }
    queue[REAR] = vl;
}
/////////////////////////////////////////////////////////////////////////////
int Dequeue()
{
    int val;
    if (FRONT == -1 || FRONT > REAR)
        printf("\nQueue Underflow");
    else 
    {
        val = queue[FRONT];
        FRONT++;
        if (FRONT > REAR)
            FRONT = REAR = -1;
            return val;
    }
}
/////////////////////////////////////////////////////////////////////////////
void Display()
{
    if (FRONT == -1 || FRONT > REAR)
        printf("\nQueue is Empty");
    else
    {
        for (int i = FRONT; i <= REAR; i++)
        printf("%d", queue[i]);
    }
}
/////////////////////////////////////////////////////////////////////////////
int peek()
{
    if (FRONT == -1 || FRONT > REAR)
    {
        printf("\nQueue is Empty");
        return -1;
    }
    else
    {
        return queue[FRONT];
    }
}
/////////////////////////////////////////////////////////////////////////////
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