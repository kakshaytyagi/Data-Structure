//menudriven.c
/* Write a menu driven to perform following operations on 2 matrices:​
1. Addition ​
2. Subtraction​
3. Multiplication
4. transpose a matrix​
*/

#include <stdio.h>
#include <conio.h>
#define MAX 50 // declare a macro & initialize with 50
//===================================== FUNCTION DECLARATION ===================================
void note();                          // to print some basic information
int add(int *, int *, int);           // addition
int subtract(int *, int *, int);      // subtraction
int multipliction(int *, int *, int); // multiplication
int Transpose(int *, int *, int);     // transpose
//===================================== FUNCTION DECLARATION ===================================

void note()
{
    printf("\nNOTE:");
    printf("\n");
    printf("\nIf you want to perform ADDITION operation then press  \"A\"");
    printf("\nIf you want to perform SUBTRACTION operation then press  \"S\"");
    printf("\nIf you want to perform MULTIPLICTION operation then press  \"M\"");
    printf("\nIf you want to perform TRANSPOSE operation then press  \"T\"");
}

//===================================== MAIN BODY ==============================================
int main()
{
    int aSize, i, j, n;
    int a[MAX], b[MAX];

    printf("Please Enter Array Size  :  ");
    scanf("%d", &aSize); // Enter the size of first array

    printf("\nPlease Enter the First Array Elements :  ");
    for (i = 0; i < aSize; i++) // Enter the elemnts of 1st array from i = 0 to size of 1st array
    {
        printf("\nEnter value at (%d) : ", i);
        scanf("%d", &a[i]); // Elements transfer to 1st array
    }

    printf("\nPlease Enter the Second Array Elements  :  ");
    for (i = 0; i < aSize; i++) // Enter the elemnts of 1st array from i = 0 to size of 2nd array
    {
        printf("\nEnter value at (%d) : ", i);
        scanf("%d", &b[i]); //// Elements transfer to 1st array
    }

    printf("\n");
    note();

    printf("\n\n\nType any of these character for performing an operation: ");
    char ch;
    ch = getche();
    switch (ch)
    {
    case 'A':
        add(a, b, aSize); // function call for addition of two arrays
        break;
    case 'S':
        subtract(a, b, aSize); // function call for subtraction of two arrays
        break;
    case 'M':
        multipliction(a, b, aSize); // function call for multiply two arrays
        break;
    case 'T':
        Transpose(a, b, aSize); // function call for transpose of an array
        break;
    default:
        printf("\n****************************** Entered wrong value **********************************\n");
    }
    return 0;
}
//======================================== MAIN BODY END ================================================

//-------------------------------------------- * A * ------------------------------------------------------
int add(int *a, int *b, int n)
{
    int i;
    int fun[MAX];
    for (i = 0; i < n; i++)
    {
        fun[i] = a[i] + b[i];
    }

    printf("\n\n After the Addtion operation : ");
    for (i = 0; i < n; i++)
    {
        printf("\n%d", fun[i]);
    }
    return 0;
}
//--------------------------------------------** END ** -------------------------------------------------------

//-------------------------------------------- * S * ----------------------------------------------------------

int subtract(int *a, int *b, int n)
{
    int i;
    int fun[MAX];
    for (i = 0; i < n; i++)
    {
        fun[i] = a[i] - b[i];
    }

    printf("\n\n After the Addtion operation : ");
    for (i = 0; i < n; i++)
    {
        printf("\n%d", fun[i]);
    }
    return 0;
}

//-------------------------------------------- **END ** -----------------------------------------------------------

//-------------------------------------------- * M * ----------------------------------------------------------
int multipliction(int *a, int *b, int n)
{
    int i;
    int fun[MAX];
    for (i = 0; i < n; i++)
    {
        fun[i] = a[i] * b[i];
    }

    printf("\n\n After the Addtion operation : ");
    for (i = 0; i < n; i++)
    {
        printf("\n%d", fun[i]);
    }
    return 0;
}
//-------------------------------------------- **END ** -----------------------------------------------------------

//-------------------------------------------- * T * ----------------------------------------------------------
int Transpose(int *a, int *b, int n)
{
    printf("\n");
    int i, j;
    int fun[MAX];
    printf("\n 1st array: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fun[j] = a[i];
        }
    }
    for (j = 0; j < n; j++)
    {
        printf("\nColumn %d): ", j);
        printf("%d", a[j]);
    }

    printf("\n 2nd array: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fun[j] = b[i];
        }
    }
    for (j = 0; j < n; j++)
    {
        printf("\nColumn %d): ", j);
        printf("%d", b[j]);
    }
    return 0;
}
//-------------------------------------------- **END ** -----------------------------------------------------------