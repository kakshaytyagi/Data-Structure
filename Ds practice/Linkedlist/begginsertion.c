// begginsertin.c
// demostrate the exmple of insertion at beginning

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node* add_a_node(struct node *ptr, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}
struct node* add_beg(struct node* head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    temp->link = head;
    head = temp;
    return head;
}
int main()
{
    int data, n;
    printf("\nEnter the how many nodes in linkedlist: ");
    scanf("%d", &n);

    printf("\nEnter the data: ");
    scanf("%d", &data);

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->link = NULL;

    struct node *ptr = head;
    for (int i = 0; i < n - 1; i++)
    {
        printf("\nEnter the data: ");
        scanf("%d", &data);
        ptr = add_a_node(ptr, data);
    }
    ptr = head;
    while(ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    printf("\nEnter the data for new node: ");
    scanf("%d", &data);
    head = add_beg(head, data);

    ptr = head;
    while(ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    return 0;
}