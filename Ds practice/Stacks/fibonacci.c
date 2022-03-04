//fibonacci.c
//demostrate the fibonoacci series

#include <stdio.h>

int fib(int a)
{
    if (a == 0)
        return 0;
    else if (a == 1)
        return 1 ;
    else
        return fib(a - 1) + fib(a - 2);
}

int main()
{
    int x;
    printf("\nEnter the range: ");
    scanf("%d", &x);

    printf("\nfibonacci series start from %d:  \n", x);
    for (int i = 0; i <= x; i++)
        printf("\t%d", fib(i));
    return 0;
}