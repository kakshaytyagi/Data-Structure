// CircularDoubly.c
// demostrate the example of circular Doubly linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *prev;
    int data;
    struct node *link;
};
struct node *head = NULL;
struct node *tail;
//////////////////////////////////////////////////////////////////////////
void creating_ll()
{
    int val;
    char option;
    printf("\nEnter the first node data: ");
    scanf("%d", &val);

    head = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    head->prev = head;
    head->data = val;
    head->link = head;
    ptr = head;

    do
    {
        printf("\nEnter the New node data: ");
        scanf("%d", &val);
        struct node *NN = (struct node *)malloc(sizeof(struct node));
        NN->prev = ptr;
        NN->data = val;
        NN->link = head;

        ptr->link = NN;
        head->prev = NN;

        ptr = NN;
        printf("\nDo you want one more node?(y/n): ");
        scanf("%s", &option);
    } while (option != 'n');
    tail = ptr;
}
//////////////////////////////////////////////////////////////////////////
void Display_ll()
{
    struct node *ptr;
    ptr = head;
    while (ptr->link != head)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->link;
    }
    printf("%d", ptr->data);
}
//////////////////////////////////////////////////////////////////////////
void insert_at_beg()
{
    int val;
    printf("\nEnter the New node data in start: ");
    scanf("%d", &val);

    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->prev = tail;
    NN->data = val;
    NN->link = head;

    head->prev = NN;
    tail->link = NN;

    head = head->prev;
}
//////////////////////////////////////////////////////////////////////////
void insert_after_node()
{
    int val, d;
    printf("\nEnter the New node data: ");
    scanf("%d", &val);

    printf("\nEnter the node data after that insertion has done: ");
    scanf("%d", &d);

    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->prev = NULL;
    NN->data = val;
    NN->link = NULL;
    struct node *ptr;
    ptr = head;
    while (ptr->data != d)
    {
        ptr = ptr->link;
    }
    NN->link = ptr->link;
    NN->prev = ptr;

    ptr->link->prev = NN;
    ptr->link = NN;
}
//////////////////////////////////////////////////////////////////////////
void insert_before_node()
{
    int val, d;
    printf("\nEnter the New node data: ");
    scanf("%d", &val);

    printf("\nEnter the node data before that insertion has done: ");
    scanf("%d", &d);

    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->prev = NULL;
    NN->data = val;
    NN->link = NULL;
    struct node *ptr;
    ptr = head;
    while (ptr->link->data != d)
    {
        ptr = ptr->link;
    }
    NN->link = ptr->link;
    NN->prev = ptr;

    ptr->link->prev = NN;
    ptr->link = NN;
}
//////////////////////////////////////////////////////////////////////////
void insert_at_end()
{
    int val;
    printf("\nEnter the New node data in start: ");
    scanf("%d", &val);

    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->prev = tail;
    NN->data = val;
    NN->link = head;

    head->prev = NN;
    tail->link = NN;
    tail = tail->link;
}
//////////////////////////////////////////////////////////////////////////
void delete_at_big()
{
    if (head == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        struct node *temp;
        temp = head;
        head = head->link;
        head->prev = tail;
        tail->link = head;

        temp->link = NULL;
        temp->prev = NULL;
        free(temp);
    }
}
//////////////////////////////////////////////////////////////////////////
void delete_at_end()
{
    if (head == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        struct node *temp;
        temp = tail;
        tail = tail->prev;
        tail->link = head;
        head->prev = tail;

        temp->link = NULL;
        temp->prev = NULL;
        free(temp);
    }
}
//////////////////////////////////////////////////////////////////////////
void delete_ll()
{
    if (head == NULL)
    {
        printf("\nEmpty");
    }
    while (head->link != head)
    {
        delete_at_big();
    }
    delete_at_big();
}
//////////////////////////////////////////////////////////////////////////
int main()
{
    int option;
    do
    {
        printf("\nEnter the choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            creating_ll();
            break;

        case 2:
            Display_ll();
            break;

        case 3:
            insert_at_beg();
            break;

        case 4:
            insert_after_node();
            break;

        case 5:
            insert_before_node();
            break;

        case 6:
            insert_at_end();
            break;

        case 7:
            delete_at_big();
            break;

        case 8:
            delete_at_end();
            break;

        case 9:
            delete_ll();
            break;
        }
    } while (option != 10);
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////