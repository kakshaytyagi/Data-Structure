//reversstring.c
//reversing the string

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char str[20], r_str[20];
    int i = 0, j;

    printf("\nEnter the string : ");
    gets(str);

    j = strlen(str) - 1;

    while (str[i] != '\0')
    {
        r_str[i] = str[j];
        i++;
        j--;
    }
    r_str[i] = '\0';
    puts(r_str);
    return 0;
}