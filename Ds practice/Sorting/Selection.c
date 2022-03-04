//Insertion.c

#include<stdio.h>

void prtArr(int* A, int n)
{
    printf("\nArray: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n){
    
    // Loop for passes
    for (int i = 0; i <= n-1; i++)
    {
        int min = i;
        printf("\nPass number %d", i);

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp;
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }

        prtArr(A,n);
    }
}

int main()
{
   int A[14];
   int n;

   printf("Enter the No. of cards for Sorting: ");
   scanf("%d",&n);

   printf("Enter the seq of card: ");
   for (int i = 0; i < n; i++)
   {
       printf("\nEnter no of %d card:  ",i+1);
       scanf("%d",&A[i]);
   }
    prtArr(A, n);
    selectionSort(A, n);
    prtArr(A, n);
    return 0;
}
