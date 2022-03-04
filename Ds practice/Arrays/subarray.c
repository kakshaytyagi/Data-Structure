//subarray.c
//demonstrate the sub array in c

#include <stdio.h>
#include <conio.h>

void fun(int const arr[])
{
    for(int i = 0; i <= 5; i++)
        printf(" %d ", arr[i]);
}

int main()
{
    int const arr[10] = {1, 2, 3, 4, 5, 6, 7};
    fun(arr);
    int *ptr;
    ptr = arr;
    arr = ptr;
    
    return 0;
}
