//exponential.c
//demostrate the example of exponential function

#include <stdio.h>
#include <math.h>

int expp(int a, int b)
{
    if(b == 0)
        return 1;
    else
    {
        return a*expp(a,b-1);
    }
}
int main()
{
    int x, y, res;
    printf("\nEnter the two numbers: ");
    scanf("%d%d", &x, &y);

    printf("\nExponential of the %d and %d: %d\n", x, y, expp(x,y));
    return 0;
}