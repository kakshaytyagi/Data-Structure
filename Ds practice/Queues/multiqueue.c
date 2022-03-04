//multiqueue.c
//demostrate the exmaple of multi-Queue

#include <stdio.h>
#include <curses.h>
#define MAX 20

int queue[MAX];
int frontL = -1, rearL = -1, frontR = MAX, rearR = MAX;
///////////////////////////////////////////////////////////////////////////////////
void EnqueueL(int val)
 {
    if (rearL == rearR - 1)
        printf("Queue Overflow");
    if (rearL == -1 && frontL == -1)
        frontL = rearL = 0;
    else
        rearL++;
    queue[rearL] = val;
 }
///////////////////////////////////////////////////////////////////////////////////
void EnqueueR(int val)
 {
    if (rearR - 1 == rearL)
        printf("Queue Overflow");
    if (rearR == MAX && frontR == MAX)
        frontR = rearR = MAX - 1;
    else
        rearR--;
    queue[rearR] = val;
 }
///////////////////////////////////////////////////////////////////////////////////
int DequeueL()
{
    int val;
    
    if (frontL == -1)
    {
        printf("Queue Underflow");
        return -1;
    }
    else
    {
        val = queue[frontL];
        frontL++;
    }
    return val;
}
///////////////////////////////////////////////////////////////////////////////////
int DequeueR()
{
    int val;
    if (frontR == MAX)
    {
        printf("Queue Underflow");
        return -1;
    }
    else
    {
        val = queue[frontR];
        frontR--;
    }
    return val;
}
///////////////////////////////////////////////////////////////////////////////////
void DisplayL()
{
    for (int i = frontL; i <= rearL; i++)
        printf("\t%d", queue[i]);
    printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////
void DisplayR()
{
    for (int i = frontR; i >= rearR; i--)
        printf("\t%d", queue[i]);
    printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////
int main()
{
    int option, val;
    do
    {
        printf("Enter the choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1: printf("Enter the Enqueue value: ");
                scanf("%d", &val);
                EnqueueL(val);
            break;

        case 2: printf("Enter the Enqueue value: ");
                scanf("%d", &val);
                EnqueueR(val);
            break;

        case 3: val = DequeueL();
                printf("Dequeue value (left queue): %d\n", val);
            break;

        case 4: val = DequeueR();
                printf("Dequeue value (Right queue): %d\n", val);
            break;

        
        case 5: printf("Queue (Left):  ");
                DisplayL();
            break;

        case 6: printf("Queue (Left):  ");
                DisplayR();
            break;
        
        default:
            break;
        }
    } while (option != 7);
    return 0;
}