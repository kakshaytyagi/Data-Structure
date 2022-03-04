//queueusinglinkedlist.c
//Write a program to implement queue operations (enqueue, dequeue, display) using Singly Linked list.

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
    printf("\n1. For Creating Queue List");
    printf("\n2. For Dequeue operation");
    printf("\n3. For Enqueue operation");
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
void enqueue()
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
void dequeue()
{
    struct node *temp;
    temp = head;
    printf("Dequeue : %d", temp->data);
    head = head->link;
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

        case 2: enqueue();
            break;

        case 3: dequeue();
            break;

        case 4: printf("Last element of the stack: %d", tail->data);
            break;
        
        case 5: display();
            break;
        
        }
    } while (option != 6);
    
}