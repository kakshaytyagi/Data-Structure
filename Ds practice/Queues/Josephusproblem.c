//Josephusproblem.c
//demostrate the exmaple of josephus problem using circular queue

#include <stdio.h>
#include <curses.h>
#define MAX 30

int queue[MAX];
int FRONT = -1, REAR = -1;
int z;

int delete()
{
    int i, val;
    if (FRONT == -1)
        printf("Overflow");
    else
    {
        val = queue[z];
        for (i = z; i <= REAR; i++)
        {
            queue[i] = queue[i + 1];
        }
    }
    return val;
}
////////////////////////////////////////////////////////////////////////
int main()
{
    int n, k, val;

    printf("\nEnter the number of people: ");
    scanf("%d", &n);

    printf("\nEnter the starting point: ");
    scanf("%d", &k);    // 3

    for (int i = 1; i <= n; i++)
    {
        REAR++;
        queue[REAR] = i;
    }
    for (int count = n; count > 1; count--) // 5
    {
        int i;
        for ( i = 0; i <= k - 1; i++)
        {
            queue[i];
        }
        z = i;
        k = delete();
    }
    return 0;   
}
///////////////////////////////////////////////////////////////////////////////