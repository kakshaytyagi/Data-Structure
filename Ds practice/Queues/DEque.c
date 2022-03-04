//DEque.c
//demostrate the double-ended queue

#include <stdio.h>
#include <curses.h>
#define MAX 20

int queue[MAX];
int front = -1, rear = -1;
////////////////////////////  INPUT     ////////////////////////////////////////////
void DEqueuemenuI()
{
    printf("\nWelcome to INPUT Restriction DEque");
    printf("\n 1. For EnQueue operation");
    printf("\n ***For DeQueue operation***");
    printf("\n\t2. Dequeue From Front: ");
    printf("\n\t3. Dequeue From Rear: ");
    printf("\n 4. For Display operation");
    printf("\n 5. For Peek operation");
    printf("\n 6. Exit");
}
/////////////////////////////////////////////////////////////////////////////////////
void Enqueue(int val)
{
    if (rear == MAX - 1)
        printf("\nQueue Overflow");
    else if (rear == -1 && front == -1)
        front = rear = 0;
    else
        rear++;
    queue[rear] = val;
}
/////////////////////////////////////////////////////////////////////////////////////
int DequeueF()
{
    int val;
    if (front == -1 || front > rear)
        printf("\nQueue Underflow");
    else
    {
        val = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;

        return val;
    }
    return -1;
}
/////////////////////////////////////////////////////////////////////////////////////
int DequeueR()
{
    int val;
    if (front == -1 || front > rear)
        printf("\nQueue Underflow");
    else
    {
        val = queue[rear];
        rear--;
        if (front > rear)
            front = rear = -1;

        return val;
    }
    return -1;
}
/////////////////////////////////////////////////////////////////////////////////////
void Display()
{
    if (front == -1 || front > rear)
        printf("\nQueue is Empty");
    else
    {
        for (int i = front; i <= rear; i++)
            printf("\t%d", queue[i]);
    }
}
/////////////////////////////////////////////////////////////////////////////////////
int peek()
{
    if  (front == -1 || front > rear)
        printf("\nQueue is Empty");
    else
    {
        return queue[front];
    }

    return -1;
}
/////////////////////////////////////////////////////////////////////////////////////
void Input()
{
    int option, val;
    DEqueuemenuI();
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

            case 2: val = DequeueF();
                    printf("value to be dequeue from the front: %d", val);
                    break;

            case 3: val = DequeueR();
                    printf("value to be dequeue from the Rear: %d", val);
                    break;

            case 4: printf("Queue: ");
                    Display();
                    break;

            case 5: val = peek();
                    printf("\nValue at the Front: %d", val);
                    break;

        }
    } while (option != 6);
}


//////////////////////////////   OUTPUT   //////////////////////////////////////////
void DEqueuemenuO()
{
    printf("\nWelcome to OUTPUT Restriction DEque");
    printf("\n ***For EnQueue operation***");
    printf("\n\t1. EnQueue from Front: ");
    printf("\n\t2. Enqueue From Rear: ");
    printf("\n 3. For Dequeue operation: ");
    printf("\n 4. For Display operation");
    printf("\n 5. For Peek operation");
    printf("\n 6. Exit");
}
/////////////////////////////////////////////////////////////////////////////////////
void EnqueueF(int val)
{
    if (rear == 0)
        printf("\nQueue Overflow");
    else if (rear == -1 || front == -1)
    {
        front = rear = (MAX/2);
        queue[front] = val;
    }
    else
    {
        front--;
        queue[front] = val;
    }
}
/////////////////////////////////////////////////////////////////////////////////////
void EnqueueR(int val)
{
    if (rear == MAX - 1)
        printf("\nQueue Overflow");
    else if (rear == -1 || front == -1)
        front = rear = (MAX/2);
    else
        rear++;
    queue[rear] = val;
}
/////////////////////////////////////////////////////////////////////////////////////
int Dequeue()
{
    int val;
    if (front == -1 || front > rear)
        printf("\nQueue Underflow");
    else
    {
        val = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;

        return val;
    }
    return -1;
}

/////////////////////////////////////////////////////////////////////////////////////
void Output()
{
    int option, val;
    DEqueuemenuO();
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: printf("\nEnter the value to queue front: ");
                    scanf("%d", &val);
                    EnqueueF(val);
                    break;

            case 2: printf("\nEnter the value to queue Rear: ");
                    scanf("%d", &val);
                    EnqueueR(val);
                    break;

            case 3: val = Dequeue();
                    printf("dequeue value: %d", val);
                    break;

            case 4: printf("Queue: ");
                    Display();
                    break;

            case 5: val = peek();
                    printf("\nValue at the Front: %d", val);
                    break;

        }
    } while (option != 6);
}
///////////////////////////   MAIN   //////////////////////////////////////////////////////


int main()
{
    int option;
    do
    {
        printf("\nNOTE: ");
        printf("\n1. Input Restricted DEque: ");
        printf("\n2. Output Restricted DEque: ");
        printf("\n3. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1: Input();
            break;
        case 2: Output();
            break;
        default: 
            break;
        }
    }while(option != 3);
    return 0;
}
/////////////////////////////////////////////////////////////////////////////