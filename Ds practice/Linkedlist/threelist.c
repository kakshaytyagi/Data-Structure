//threelist.c
//Creating three nodes in linklist

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int count_of_node(struct node *head)
{
    int count = 0;
    if(head == NULL)
    {
        printf("Linked List is Empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr -> link;
    }
    printf("%d", count);
}

int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current -> data = 100;
    current-> link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 999;
    current->link = NULL;

    head->link->link = current;

    count_of_node(head);
}