//reverse_ll.c
//Write a program to reverse a single linked list.​
//Hint: use stacks

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;
///////////////////////////////////////////
struct node
{
    int data;
    struct node *link;
};
//////////////////////////////////////////
void creating_ll(struct node *ptr)
{
    int val;
    char option;
    do
    {
        printf("\nEnter the data in new node: ");
        scanf("%d", &val);

        struct node *NN = (struct node*)malloc(sizeof(struct node));
        NN->data = val;
        NN->link = NULL;

        ptr->link = NN;
        ptr = NN;
        printf("\nDo you want to insert one more node? (y/n): ");
        scanf("%s", &option);
    } while (option != 'n');
}
////////////////////////***push***////////////////////////////////////
void push(int val)
{
    if (top == MAX - 1)
        printf("\nStack Overflow");
    else
    {
        top++;
        stack[top] = val;
    }
}
/////////////////////////***pop***////////////////////////////////
int pop()
{
    int val = 0;
    if (top == -1)
        printf("\nStack Underflow");
    else
    {
        val = stack[top];
        top--;
    }
    return val;
}
/////////////////////////***Display***////////////////////////////////////
void display_ll(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->link;
    }
}
//////////////////////////////////////////////////////////////////
int main()
{
    int val;
    printf("\nEnter the data in first node: ");
    scanf("%d", &val);

    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = val;
    head->link = NULL;

    creating_ll(head);
    printf("\nOriginal Linkedlist: ");
    display_ll(head);
    struct node *ptr;
    ptr = head;
    while ( ptr != NULL)
    {
        push(ptr->data);
        ptr = ptr->link;
    }
    ptr = head;
    while (ptr != NULL)
    {
        ptr->data = pop();
        ptr = ptr->link;
    }
    printf("\nReversed Linkedlist: ");
    display_ll(head);
    printf("\n");
    return 0;
}
