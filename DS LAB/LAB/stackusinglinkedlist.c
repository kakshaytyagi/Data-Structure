//stackusinglinkedlist.c
//Write a program to implement stack operations (push, pop, display) using Singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *head;
struct node *tail;
///////////////////////////////////////////////////////////////////////
void menu()
{
    printf("\n1. For Creating Stack List");
    printf("\n2. For Push operation");
    printf("\n3. For Pop operation");
    printf("\n4. For Peek operation");
    printf("\n5. For Display");
    printf("\n6. EXIT");
}
///////////////////////////////////////////////////////////////////////
void creating_ll()
{
    int data;
    char option;

    printf("Enter the data: ");
    scanf("%d",&data);

    struct node *ptr;
    ptr = head;
    ptr->data = data;
    ptr->link = NULL;

    do
    {
        printf("Enter the data: ");
        scanf("%d",&data);

        struct node *NN = (struct node*)malloc(sizeof(struct node));
        NN->data = data;
        NN->link = NULL;

        ptr->link = NN;
        ptr = ptr->link;
        tail = ptr;
        printf("Do you want one more node?(y/n): ");
        scanf("%s",&option);
    } while (option != 'n');
}
///////////////////////////////////////////////////////////////////////
void push()
{
    int data;

    printf("Enter the data: ");
    scanf("%d",&data);

    struct node *NN = (struct node*)malloc(sizeof(struct node));
    NN->data = data;
    NN->link = NULL;

    tail->link = NN;
    tail = tail->link;
}
///////////////////////////////////////////////////////////////////////
void pop()
{
    struct node *ptr;
    ptr = head;

    while(ptr->link->link != NULL)
    {
        ptr = ptr->link;
    }
    struct node *temp;
    temp = ptr->link;
    ptr->link = NULL;
    tail = ptr;
    free(temp);
}
///////////////////////////////////////////////////////////////////////
void display()
{
    struct node *ptr;
    ptr = head;

    while(ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }

}
///////////////////////////////////////////////////////////////////////
int main()
{
    head = (struct node*)malloc(sizeof(struct node));
    int option;
    menu();
    do
    {
        printf("\nEnter the choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1: creating_ll();
            break;

        case 2: push();
            break;

        case 3: pop();
            break;

        case 4: printf("Last element of the stack: %d", tail->data);
            break;
        
        case 5: display();
            break;
        
        }
    } while (option != 6);
    
}