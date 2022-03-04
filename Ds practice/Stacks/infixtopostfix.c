//infixtopostfix.c
//convertion of infix expression to postfix expression

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define N 100

char stk[N];
int top = -1;

///////////////////////////////////////////////////////////////////////////////////

void pushr(char vl)
{
    if (top == N - 1)
        printf("\nStack is Overflow");
    else
    {
        stk[top] = vl;
        top++;
    }
}


//////////////////////////////////////////////////////////////////////////////////

char popr()
{
    char vl;
    if (top == -1)
        printf("\nStack is Underflow");
    else
    {
        return stk[top--];
    }
}
//////////////////////////////////////////////////////////////////////////////////

int getpriority(char vl)
{
    if (vl == '^')
        return 3;
    else if (vl == '*' || vl == '/' || vl == '%')
        return 2;
    else if (vl == '+' || vl == '-')
        return 1;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////
int main()
{
    char exp[N]; 
    char x;
    int i = 0;
    printf("\nEnter the expression : ");
    scanf("%s", exp);

    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
            pushr(exp[i]);

        else if (exp[i] == ')')
        {
            int j;
            j = top;
            while (stk[j] != '(')
            {
                x = popr();
                printf("%c ", x);
                j--;   
            }

            if (top == -1)
            {
                exit(1);
            }
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '^' || exp[i] == '%')
        {
            while (getpriority(stk[top]) > getpriority(exp[i]))
            {
                printf("%c",popr());
            }
            pushr(exp[i]);
        }
        else if ('a' <= exp[i] <= 'z' || 'A' <= exp[i] <= 'Z')
            printf("%c", exp[i]);

        else
        {
            printf("\nIncorrect element in expression ");
            exit(1);
        }
        i++;
    }
    while (top != -1)
        {
            printf("%c", popr());
        }

    return 0;
}