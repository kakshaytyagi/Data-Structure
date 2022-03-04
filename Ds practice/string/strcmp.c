//strcmp.c
//compairing the two string

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char str_1[20], str_2[20];
    int i = 0, j = 0, len_1 = 0, len_2 = 0, same = 0;

    printf("\nEnter the first string: ");
    gets(str_1);
    printf("\nEnter the second string: ");
    gets(str_2);

    len_1 = strlen(str_1);
    len_2 = strlen(str_2);

    if (len_1 != len_2)
        printf("\nTwo strings are not equal.");

    if (len_1 == len_2)
    {
        while (i < len_1)
        {
            if (str_1[i] == str_2[i])
                i++;
            else
                break;
        }
        if (i == len_1)
        {
            same = 1;
            printf("\nTwo strings are equal");
        }
    }
    if (same == 0)
    {
        if (str_1 > str_2)
            printf("\nString 1 is greater than string 2");
        else
            printf("\n string 2 is greater than string 1");
    }
        return 0;
}