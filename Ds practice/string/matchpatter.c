//matchpattern.c
//program to demostrate the pattern matching

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char str[50], sub_str[30];
    int i = 0, l, max , j = 0, index = 0;

    printf("\nEnter the main string: ");
    gets(str);
    printf("\nEnter the sub string: ");
    gets(sub_str);

    max = strlen(str) - strlen(sub_str) + 1;
    while (str[i] != '\0')
    {
        l = i;
        while (str[l] == sub_str[j] && sub_str[j] != '\0')
        {
            l++;
            j++;
        }
    }

    return 0;
}