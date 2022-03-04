//towerofhanoi.c
//demostrate the example of tower of hanoi

#include <stdio.h>
#include <math.h>

void move(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
        printf("\nMove from %c to %c", source, destination);
    else
    {
        move(n-1,source,destination,auxiliary);
        move(1,source,auxiliary,destination);
        move(n-1,auxiliary,source,destination);
    }
}
int main()
{
    int n;
    printf("\nEnter the no. of rings : ");
    scanf("%d", &n);

    move(n,'A','B','C');
    return 0;
}
