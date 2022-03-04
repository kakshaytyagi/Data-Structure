//bubble.c

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
 
void bubbleSort(int *A, int n){
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
}
 
int main(){
   int A[14];
   int n;

   printf("Enter the No. of Cards for Sorting: ");
   scanf("%d",&n);

   printf("Enter the seq of card to sort: ");
   for (int i = 0; i < n; i++)
   {
       printf("\nEnter no of %d card:  ",i+1);
       scanf("%d",&A[i]);
   }
    prtArr(A, n); // Printing the array before sorting
    bubbleSort(A, n); // Function to sort the array
    prtArr(A, n); // Printing the array before sorting
    return 0;
}
