//groundedheaderll.c
//demostrate the example of grounded header linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
////////////////////////////////////////////////////////////////////////////
void creating_ll()
{
    int val;
    char option;

    do
    {
        printf("\nEnter the New node data: ");
        scanf("%d", &val);
        struct node *NN = (struct node *)malloc(sizeof(struct node));
        NN->data = val;
        NN->link = NULL;

        
        printf("\nDo you want one more node?(y/n): ");
        scanf("%s", &option);
    } while (option != 'n');
}
////////////////////////////////////////////////////////////////////////////
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
        }

    }while(option != 5);
}
///////////////////////////////////////////////////////////////////////////////////////

