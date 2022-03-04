//insertelement.c
//inserting an element in an array

#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[10], pos, val, i, N;

    printf("Enter the no. of element of array: ");
    scanf("%d", &N);

    printf("Enter the element in an array: ");
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("Enter the value and its postion : ");
    scanf("%d %d", &val, &pos);

    for (i = N - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    N = N + 1;
    arr[pos] = val;
    for (i = 0; i < N; i++)
        printf("%d", arr[i]);
    return 0;
}