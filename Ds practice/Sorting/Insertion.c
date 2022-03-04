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

void insertionSort(int *A, int n){
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n-1; i++)
    {
         printf("\nPass number %d", i);

        key = A[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;

        prtArr(A,n);
    }
}

int main(){
   
    
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
    insertionSort(A, n);
    prtArr(A, n);
    return 0;
}
