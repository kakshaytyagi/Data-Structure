//parentheses.c
//program to check the parentheses in expression

#include <stdio.h>
#include <string.h>
#define MAX 30

int top = -1;
int stk[MAX];

void push(char a)
{
    if (top == MAX - 1)
        printf("\n Stack Overflow");
    else
    {
        stk[++top] = a;
    }
}

char pop()
{
    char a;
    if (top == -1)
        printf("\n Stack underflow");
    else
    {
        a = stk[top];
        top--;
        return a;
    }
}


int main()
{
    char s[MAX], temp;
    int flag = 1;

    printf("\nEnter the expression: ");
    fgets(s, sizeof(s), stdin);

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            push(s[i]);
        else if (s[i] == ']' || s[i] == '}' || s[i] == ')')
            if (top == -1)
                flag = 0;
            else
            {
                temp = pop();
                if (s[i] == ')' && (temp == '[' || temp == '{'))
                    flag = 0;
                if (s[i] == '}' && (temp == '[' || temp == '('))
                    flag = 0;
                if (s[i] == ']' && (temp == '(' || temp == '{'))
                    flag = 0;
            }     
    }
    if (top >= 0)
        flag = 0;
    if (flag == 1)
        printf("\n Valid expression\n");
    else 
        printf("\n Invalind Expression\n");
}
