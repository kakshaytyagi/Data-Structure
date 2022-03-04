// circularlinkedlist.c
// demostrate the example of circular linkedlist all operation

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
////////////////////////////****MENU****/////////////////////////////
void linkedlistmenu()
{
    printf("\n1. For Creating linked list");
    printf("\n2. For Insertion at beginning in linked list");
    printf("\n3. For Insertion at end in linked list");
    printf("\n4. For delete at beginning in linked list");
    printf("\n5. For delete at end in linked list");
    printf("\n6. For Display linked list");
    printf("\n7. For complete Delete linked list");
    printf("\n8. Exit");
}
////////////////////////////****Creating ll****/////////////////////////////
struct node *creating_ll(struct node *start)
{
    int val, opt;

    printf("\nEnter the data for first node: ");
    scanf("%d", &val);
    struct node *temp;
    temp = start;
    start->data = val;
    start->link = start;

    do
    {
        printf("\nEnter the data for new node: ");
        scanf("%d", &val);

        struct node *NN = (struct node *)malloc(sizeof(struct node));
        NN->data = val;
        NN->link = temp;

        start->link = NN;
        start = start->link;
        printf("\nDo you want one more node? (1/0): ");
        scanf("%d", &opt);
    } while (opt != 0);
    return temp;
}
////////////////////////////****Insert at beginning****/////////////////////////////
struct node* insert_at_beg_ll(struct node* start)
{
    int val;
    printf("\nEnter the data for new start node: ");
    scanf("%d", &val);

    struct node *temp;
    temp = start;
    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->data = val;
    NN->link = start;

    while (temp->link != start)
    {
        temp = temp->link;
    }
    temp->link = NN;
    start = NN;
    return NN;
}
////////////////////////////****Insert at end****/////////////////////////////
void insert_at_last_ll(struct node *start)
{
    int val;
    printf("\nEnter the data for new last node: ");
    scanf("%d", &val);

    struct node *temp;
    temp = start;
    struct node *NN = (struct node *)malloc(sizeof(struct node));
    NN->data = val;
    NN->link = start;

    while (temp->link != start)
    {
        temp = temp->link;
    }
    temp->link = NN;
}
////////////////////////////****delete at beginning****/////////////////////////////
struct node* delete_at_beg_ll(struct node *start)
{
    if (start == NULL)
        printf("\nUnderflow");
    else
    {
        struct node *temp, *ptr;
        ptr = start;
        while(ptr->link != start)
        {
            ptr = ptr->link;
        }
        temp = ptr->link;
        ptr->link = start->link;
        start = start->link;
        // free(temp);
        // temp = NULL;
        return start;
    }
}
////////////////////////////****delete at end****/////////////////////////////
void delete_at_end_ll(struct node *start)
{
    if (start == NULL)
        printf("\nUnderflow");
    else
    {
        struct node *ptr, *temp;
        ptr = start;
        while (ptr->link->link != start)
        {
            ptr = ptr->link;
        }
        temp = ptr->link;
        ptr->link = start;
        free(temp);
        temp = NULL;
    }
}
////////////////////////////****delete at end****/////////////////////////////
void delete_ll(struct node *start)
{
    if (start == NULL)
        printf("\nFirst Create linked list!!");
    else
    {
        struct node *ptr;
        ptr = start;
        while (ptr->link != start)
            start = delete_at_beg_ll(start);
        free(start);
    }
}
////////////////////////////****DISPLAY****/////////////////////////////
void Display_ll(struct node *ptr)
{
    struct node *temp;
    temp = ptr;
    while (temp->link != ptr)
    {
        printf("%d-> ", temp->data);
        temp = temp->link;
    }
    printf("%d-> ", temp->data);
}
////////////////////////////****MAIN****/////////////////////////////
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
            insert_at_last_ll(head);
            break;

        case 4:
            head = delete_at_beg_ll(head);
            break;

        case 5:
            delete_at_end_ll(head);
            break;

        case 6:
            Display_ll(head);
            break;

        case 7:
            delete_ll(head);
            break;

        }
    } while (option != 8);
    return 0;
}


