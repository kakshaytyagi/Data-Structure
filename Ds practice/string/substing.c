//substring.c
//make a substring from a string

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char str[200], sub_str[200];
    int i = 0, j, n;

    printf("\nEnter the string: ");
    gets(str);

    printf("\nEnter the starting point of substring: ");
    scanf("%d", &j);

    printf("\nEnter the last of substring: ");
    scanf("%d", &n);

    while (str[i] != '\0' && n > 0)
    {
        sub_str[i] = str[j];
        i++;
        j++;
        n--;
    }
    sub_str[i] = '\0';
    puts(sub_str);
    return 0;
}