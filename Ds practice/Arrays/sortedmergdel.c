//sortedmergdel.c
//inserting and deleting operation on sorted array
#include<stdio.h>
#include<conio.h>

int main()
{
    int arr[20], val, i, N;

    printf("Enter the no. of element of array: ");
    scanf("%d", &N);

    printf("Enter the element in an array: ");
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("Enter the value : ");
    scanf("%d", &val);

    for (i = 0; i <= N; i++)
    {
        if (arr[i] > val)
        {
            for (int j = N; j >= i; j--)
                arr[j + 1] = arr[j];
            arr[i] = val;
            break;
        }
    }
    N = N + 1;
    printf("After inserting : ");
    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);
//-------------------------   *Deletion* --------------------------------------------
    printf("\nEnter the del. value : ");
    scanf("%d", &val);

    for (i = 0; i <= N; i++)
    {
        if (arr[i] > val)
        {
            for (int j = i; j < N; j++)
                arr[j - 1] = arr[j];
            break;
        }
    }
    N = N - 1;
    printf("After deleting : ");
    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);
    
    return 0;
}