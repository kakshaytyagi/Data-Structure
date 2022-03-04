//concatstring.c
//concatenation of the two strings

#include <stdio.h>
#include <conio.h>

int main()
{
    char str_1[30], str_2[30];
    int k = 0, j = 0;

    printf("\nEnter the two string: ");
    gets(str_1);
    gets(str_2);

    while(str_1[j] != '\0')
        j++;

    while(str_2[k] != '\0')
    {
        str_1[j] = str_2[k];
        j++;
        k++;
    }
    str_1[j] = '\0';
    puts(str_1);
    return 0;
}