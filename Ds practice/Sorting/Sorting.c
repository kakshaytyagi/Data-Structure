//Sorting.c

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
///////////////////////////////////////////////////////
void bubbleSort(int *A, int n)
{
    int temp;
    
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        printf("\nPass number %d:\n", i+1);
        
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;    
            } 
            prtArr(A, n);
        } 
    } 
    prtArr(A, n);
}
///////////////////////////////////////////////////////
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
    prtArr(A, n);
}
///////////////////////////////////////////////////////
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
    prtArr(A, n);
}
///////////////////////////////////////////////////////

int main()
{
   int A[14], n, option;

   printf("Enter the No. of Cards for Sorting: ");
   scanf("%d",&n);

   printf("Enter the seq of card to sort: ");
   for (int i = 0; i < n; i++)
   {
       printf("\nEnter no of %d card:  ",i+1);
       scanf("%d",&A[i]);
   }

   prtArr(A, n);
   do
   {
       printf("\nEnter the choice: ");
       scanf("%d", &option);

       switch (option)
       {
       case 1: bubbleSort(A, n);
           break;
       case 2: insertionSort(A, n);
           break;
       case 3: selectionSort(A, n);
           break;
       }
       
   } while (option != 4);
   prtArr(A, n);
   return 0;
}