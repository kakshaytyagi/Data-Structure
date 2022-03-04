// doublyll.c
// demostrate the doubly linked list insertion and deletion

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *link;
};
//////////////////////////////////////////////////////////////////////////
void linkedlistmenu()
{
    printf("\n1. For Creating linked list");
    printf("\n2. For Insertion at beginning in linked list");
    printf("\n3. For Insertion after a node in linked list");
    printf("\n4. For Insertion before a node in linked list");
    printf("\n5. For Insertion at end in linked list");
    printf("\n6. For delete at beginning in linked list");
    printf("\n7. For delete a node in linked list");
    printf("\n8. For delete at end in linked list");
    printf("\n9. For Display linked list");
    printf("\n10. Exit");
}
//////////////////////////////////////////////////////////////////////////
struct node *creating_ll(struct node *start)
{
    int val;
    char opt;

    printf("\nEnter the data for first node: ");
    scanf("%d", &val);
    struct node *temp;
    temp = start;
    start->data = val;
    start->link = NULL;
    start->prev = NULL;

    do
    {
        printf("\nEnter the data for new node: ");
        scanf("%d", &val);

        struct node *NN = (struct node *)malloc(sizeof(struct node));
        NN->prev = start;
        NN->data = val;
        NN->link = NULL;

        start->link = NN;
        start = start->link;
        printf("\nDo you want one more node? (y/n): ");
        scanf("%s", &opt);
    } while (opt != 'n');
    return temp;
}
//////////////////////////////////////////////////////////////////////////
struct node *insert_at_beg_ll(struct node *start)
{
    int val;
    printf("\nEnter the data for new start node: ");
    scanf("%d", &val);

    struct node *temp;
    temp = start;
    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->prev = NULL;
    NN->data = val;
    NN->link = start;

    temp->prev = NN;
    start = NN;
    return start;
}
//////////////////////////////////////////////////////////////////////////
void after_node_insetion(struct node *ptr)
{
    int data, val;
    printf("\nEnter the data: ");
    scanf("%d", &data);

    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->prev = NULL;
    NN->data = data;
    NN->link = NULL;

    printf("\nEnter the Node after that value will insert: ");
    scanf("%d", &val);

    struct node *temp1, *temp2;
    while (ptr->data != val)
    {
        ptr = ptr->link;
    }
    temp1 = ptr;
    temp2 = temp1->link;

    temp1->link = NN;
    NN->prev = temp1;
    temp2->prev = NN;
    NN->link = temp2;
}
//////////////////////////////////////////////////////////////////////////
void before_node_insetion(struct node *ptr)
{
    int data, val;
    printf("\nEnter the data: ");
    scanf("%d", &data);

    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->prev = NULL;
    NN->data = data;
    NN->link = NULL;

    printf("\nEnter the Node after that value will insert: ");
    scanf("%d", &val);

    struct node *temp1, *temp2;
    while (ptr->data != val)
    {
        ptr = ptr->link;
    }
    temp2 = ptr;
    temp1 = temp2->prev;

    temp1->link = NN;
    NN->prev = temp1;
    temp2->prev = NN;
    NN->link = temp2;
}
//////////////////////////////////////////////////////////////////////////
void insert_at_last_ll(struct node *ptr)
{
    int val;
    printf("\nEnter the data for last start node: ");
    scanf("%d", &val);

    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->prev = NULL;
    NN->data = val;
    NN->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = NN;
    NN->prev = ptr;
}
//////////////////////////////////////////////////////////////////////////
struct node *delete_at_beg_ll(struct node *start)
{
    if (start == NULL)
    {
        printf("UNDERFLOW");
        return NULL;   
    }
    else
    {
        struct node *temp;
        temp = start;
        start = start->link;
        start->prev = NULL;
        temp->link = NULL;
        return start;
    }
}
//////////////////////////////////////////////////////////////////////////
void delete_at_end_ll(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        struct node *temp;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        temp = ptr;
        ptr = ptr->prev;
        ptr->link = NULL;
        temp->prev = NULL;
        free(temp);
    }
}
//////////////////////////////////////////////////////////////////////////
void delete_after_node(struct node *ptr)
{
    int val;
    printf("\nEnter the delete node data: ");
    scanf("%d", &val);
    if (ptr == NULL)
        printf("\nUnderflow");
    struct node *temp1, *temp2;
    while (ptr->data != val)
    {
        ptr = ptr->link;
    }
    temp1 = ptr->prev;
    temp2 = ptr->link;
    temp1->link = temp2;
    temp2->prev = temp1;
    free(ptr);
}
//////////////////////////////////////////////////////////////////////////
void Display_ll(struct node *ptr)
{
    struct node *temp;
    temp = ptr;
    while (temp->link != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->link;
    }
    printf("%d-> ", temp->data);
}
//////////////////////////////////////////////////////////////////////////
int main()
{
    int option;
    struct node *head = (struct node*)malloc(sizeof(struct node));
    linkedlistmenu();
    do
    {
        printf("\nEnter the choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            head = creating_ll(head);
            break;

        case 2:
            head = insert_at_beg_ll(head);
            break;

        case 3:
            after_node_insetion(head);
            break;

        case 4:
            before_node_insetion(head);
            break;

        case 5:
            insert_at_last_ll(head);
            break;

        case 6:
            head = delete_at_beg_ll(head);
            break;

        case 7:
            delete_after_node(head);
            break;

        case 8:
            delete_at_end_ll(head);
            break;

        case 9:
            Display_ll(head);
            break;
        }
    } while (option != 10);
    return 0;
}
///////////////////////////////////////////////////////////////////////////