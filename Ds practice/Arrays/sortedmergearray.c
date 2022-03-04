//sortedmergedarray.c
//write a program to merge two sorted array

#include <stdio.h>
#include <conio.h>

int main()
{
    int arr_1[20], arr_2[20], arr[40];
    int i, n, m, index = 0;
    int index_1 = 0, index_2 = 0;

    printf("\nEnter the no. of elements in first array : ");
    scanf("%d", &n);
    printf("\nEnter the no. of elements in second array : ");
    scanf("%d", &m);

    printf("\nEnter the element in first array: \n");
    for (i = 0; i <= n; i++)
        scanf("\n%d", &arr_1[i]);

    printf("\nEnter the element in second array: \n");
    for (i = 0; i <= m; i++)
        scanf("\n%d", &arr_2[i]);

    while (index_1 < n && index_2 < m)
    {
        if (arr_1[index_1] < arr_2[index_2])
        {
            arr[index] = arr_1[index_1];
            index_1++;
        }
        else
        {
            arr[index] = arr_2[index_2];
            index_2++;
        }
        index++;
    }
    if (index_1 == n)
    {
        while (index_2 < m)
        {
            arr[index] = arr_2[index_2];
            index_2++;
            index++;
        }
    }
    else if (index_2 == m)
    {
        while (index_1 < n)
        {
            arr[index] = arr_2[index_2];
            index_2++;
            index++;
        }
    }

    printf("\n The merged array: ");
    for (i = 0; i < index; i++)
        printf(" %d ", arr[i]);
    return 0;
}