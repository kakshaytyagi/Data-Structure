//endinsertion.c
//demostrate the example of insertion of node at the end of the linkedlist

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *link;
};
//////////////////////////////////////////////////////////////////////////
void create_list(struct node *ptr)
{
    int option, data;
    do
    {
        printf("\nEnter the data: ");
        scanf("%d", &data);

        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->link = NULL;

        ptr->link = temp;
        ptr = temp;
        printf("\nEnter the choice(1/0): ");
        scanf("%d", &option);
    } while (option != 0);
    
}
//////////////////////////////////////////////////////////////////////////
void end_insertion(struct node *ptr)
{
    int data;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    printf("\nEnter the data: ");
    scanf("%d", &data);

    struct node *NN = (struct node*)malloc(sizeof(struct node));
    NN->data = data;
    NN->link = NULL;

    ptr->link = NN;
}
//////////////////////////////////////////////////////////////////////////
void display_list(struct node *ptr)
{
    printf("\nLinkedlist: ");
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->link;
    }
}
//////////////////////////////////////////////////////////////////////////
int main()
{
    int data;
    printf("\nEnter the data: ");
    scanf("%d", &data);

    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = data;
    head->link = NULL;
    create_list(head);
    display_list(head);
    end_insertion(head);
    display_list(head);
    printf("\n");
    free(head);
    head = NULL;
    return 0;
}