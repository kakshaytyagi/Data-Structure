//Traversinglinklist.c
//Traversomg a Single Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
void print_data(struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("Linked List is Empty");

    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        printf(" %d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\nNo. of Nodes are : %d", count);
}

int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data = 100;
    current->link = NULL;
    head->link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 200;
    current->link = NULL;
    head->link->link = current;


    print_data(head);
}