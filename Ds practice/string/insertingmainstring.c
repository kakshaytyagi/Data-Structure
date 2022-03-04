//insertingmainstring
//inserting a substring into the main string

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char str[100], sub_str[50], f_str[100];
    int i, j, index = 0, n = 0;

    printf("\nEnter the main string: ");
    gets(str);

    printf("\nEnter the sub_sting : ");
    gets(sub_str);

    printf("\nEnter the position you want to insert from in main string: ");
    scanf("%d", &j);

    for (i = 0; i < j; i++)
    {
        f_str[index] = str[n];
        index++;
        n++;
    }
    for (i = 0; i < strlen(sub_str); i++)
    {
        f_str[index] = sub_str[i];
        index++;
    }
    for (i = n; i < strlen(str); i++)
    {
        f_str[index] = str[n];
        index++;
        n++;
    }
    f_str[index] = '\0';
    puts(f_str);
    return 0;
}