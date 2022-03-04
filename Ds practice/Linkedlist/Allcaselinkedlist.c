// Allcaselinkedlist.c
// A linkedlist all operation

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *link;
};
////////////////////////////////  **MENU**   /////////////////////////////////
void linkedlistmenu()
{
    printf("\n1. For Creating linked list");
    printf("\n2. For Insertion at beginning in linked list");
    printf("\n3. For Insertion after a node in linked list");
    printf("\n4. For Insertion before a node in linked list");
    printf("\n5. For Insertion at end in linked list");
    printf("\n6. For delete at beginning in linked list");
    printf("\n7. For delete after a node in linked list");
    printf("\n8. For delete at end in linked list");
    printf("\n9. For Display linked list");
    printf("\n10. Exit");
}
////////////////////////////////  **CREATING**   /////////////////////////////////
void create_list(struct node *ptr)
{
    int option, data;
    do
    {
        printf("\nEnter the data: ");
        scanf("%d", &data);

        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->link = NULL;

        ptr->link = temp;
        ptr = temp;
        printf("\nEnter the choice(1/0): ");
        scanf("%d", &option);
    } while (option != 0);
}
/////////////////////////////////   **Beg Insertion**   ///////////////////////////////////
void beg_insertion(struct node **ptr)
{
    int data;
    printf("\nEnter the data: ");
    scanf("%d", &data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    temp->link = *ptr;
    *ptr = temp;
}
/////////////////////////////////   **After a node Insertion**   ///////////////////////////////////
void after_node_insetion(struct node *ptr)
{
    int data, val;
    printf("\nEnter the data: ");
    scanf("%d", &data);

    struct node *NN = (struct node *)malloc(sizeof(struct node));
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
    NN->link = temp2;
}
/////////////////////////////////   **before a node Insertion**   ///////////////////////////////////
void before_node_insetion(struct node *ptr)
{
    int data, val;
    printf("\nEnter the data: ");
    scanf("%d", &data);

    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->data = data;
    NN->link = NULL;

    printf("\nEnter the Node before that value will insert: ");
    scanf("%d", &val);

    struct node *temp1, *temp2;
    while (ptr->data != val)
    {
        temp1 = ptr;
        ptr = ptr->link;
    }
    temp2 = ptr;

    temp1->link = NN;
    NN->link = temp2;
}
/////////////////////////////////   **End Insertion**   ///////////////////////////////////
void end_insertion(struct node *ptr)
{
    int data;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    printf("\nEnter the data: ");
    scanf("%d", &data);

    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->data = data;
    NN->link = NULL;

    ptr->link = NN;
}
//////////////////////////////////   **Delete at beginning**   /////////////////////////////
struct node *delete_at_big(struct node *ptr)
{
    if (ptr == NULL)
        printf("Underflow");
    struct node *temp;
    temp = ptr;
    ptr = ptr->link;
    free(temp);
    temp = NULL;
    return ptr;
}
//////////////////////////////////   **Delete at end**   /////////////////////////////
void delete_at_end(struct node *ptr)
{
    if (ptr == NULL)
        printf("\nUnderflow");
    struct node *temp1, *temp2;
    while (ptr->link != NULL)
    {
        temp1 = ptr;
        ptr = ptr->link;
    }
    temp1->link = NULL;
    temp2 = ptr;
    free(temp2);
    temp2 = NULL;
}
//////////////////////////////////   **Delete after node**   /////////////////////////////
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
        temp1 = ptr;
        ptr = ptr->link;
    }
    temp2 = ptr;
    ptr = ptr->link;
    temp1->link = ptr;
    free(temp2);
    temp2 = NULL;
}
//////////////////////////////////   **Display**   /////////////////////////////
void display_list(struct node *ptr)
{
    printf("\nLinkedlist: ");
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->link;
    }
}
/////////////////////////////////////   **MAIN**    ///////////////////////////
int main()
{
    int data, option;
    linkedlistmenu();
    printf("\nEnter the choice: ");
    scanf("%d", &option);

    printf("\nEnter the data: ");
    scanf("%d", &data);

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->link = NULL;
    do
    {
        switch (option)
        {
        case 1:
            create_list(head);
            break;
        case 2:
            beg_insertion(&head);
            break;
        case 3:
            after_node_insetion(head);
            break;
        case 4:
            before_node_insetion(head);
            break;
        case 5:
            end_insertion(head);
            break;
        case 6:
            head = delete_at_big(head);
            break;
        case 7:
            delete_after_node(head);
            break;
        case 8:
            delete_at_end(head);
            break;
        case 9:
            display_list(head);
            break;
        }
        printf("\nEnter the choice: ");
        scanf("%d", &option);

    } while (option != 10);
    printf("\n");
    return 0;
}
