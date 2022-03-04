//Greatestcf.c
//find the GCF 

#include <stdio.h>
#include <math.h>

int GCD(int a, int b)
{
    if (a%b == 0)
        return b;
    else
    {
        return GCD(b,a%b);
    }
}
int main()
{
    int x, y, res;
    printf("\nEnter the two numbers: ");
    scanf("%d%d", &x, &y);

    printf("\nGreatest common factor of %d and %d: %d\n", x, y, GCD(x,y));
    return 0;
}
