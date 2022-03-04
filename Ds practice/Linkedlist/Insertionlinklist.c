//insertionlinklist.c
//insertion of a node in linklist

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void add_at_end(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d ", ptr-> data);
        ptr = ptr->link;
    }
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = (struct node *)(malloc(sizeof(struct node)));
    current->data = 100;
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 999;
    current->link = NULL;

    head->link->link = current;
    add_at_end(head, 23);
}
