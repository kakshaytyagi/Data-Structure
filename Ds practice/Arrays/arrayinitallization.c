//arrayinitallization.c
// array initallization practice

#include<stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6}, j;
    j = sizeof(arr)/ sizeof(arr[0]);
    printf("%u ", j);
    scanf("%d", &arr[j]);
    arr[j] = 100;
    j = sizeof(arr)/ sizeof(arr[0]);
    printf("%u", j);

    return 0;
}