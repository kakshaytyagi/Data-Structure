//sorting.c
//program to sort the name of students

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char name[5][10], temp[20];
    int i, n, j;

    printf("\nEnter the no. of student : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the name of student: ");
        gets(name[i]);
    }
    for(i = 0; i <= n; i++)
    {
        for (j = 0; j <= n - i - 1; j++)
        {
            if(strcmp(name[j], name[j+1]) > 0)
            {
                strcpy(temp, name[j]);
                strcpy(name[j], name[j+1]);
                strcpy(name[j+1], temp);
            }
        }
    }
    printf("\n Name of the students in alphabetical order are: ");
    for(i = 0; i <= n; i++){
        puts(name[i]);
    }
    return 0;
}