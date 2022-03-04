//mergearray.c
//merging the two array

#include <stdio.h>
#include <conio.h>

int main()
{
    int arr_1[20], arr_2[20], arr_f[50]; // declare three arrays
    int N, M, i, j, INDEX = 0;
    printf("\nEnter the no. of element of 1st array: "); // INPUT N
    scanf("%d", &N);                                     //

    printf("\nEnter the element in an array: ");
    for (i = 0; i < N; i++)     // [INITLIZATION] i = 0 repeat Next step until i < N
        scanf("%d", &arr_1[i]); //

    printf("\nEnter the no. of element of 2nd array: "); // INPUT M
    scanf("%d", &M);                                     //

    printf("\nEnter the element in an array: ");
    for (i = 0; i < M; i++)     // [INITLIZATION] i = 0 repeat Next step until i < M
        scanf("%d", &arr_2[i]); //

    for (j = 0; j < N; j++)
    {
        arr_f[INDEX] = arr_1[j]; // transfer 1st array
        INDEX++;
    }
    for (j = 0; j < M; j++)
    {
        arr_f[INDEX] = arr_2[j]; // transfer 2nd array
        INDEX++;
    }

    printf(" %d )", arr_2[j]);
    printf("\nMerging array: "); // PRINT merged array
    for (j = 0; j < INDEX; j++)  //SET j = 0 & Repeat until j < INDEX
    {
        printf(" %d ", arr_f[j]); //
    }
    return 0;
}