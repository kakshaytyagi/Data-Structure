//bestinsertionoflinklist.c
//Optimal way of insertion of node in a link list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *add_at_end(struct node *ptr, int data) /*make add_at_end function with return type struct node*
passing with argument is ptr and data(placed in next node)*/
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)); //creating the next node as temp
    temp->data = data;                                              // assigned value in temp data part
    temp->link = NULL;                                              // assigned NULL in link part of temp

    ptr->link = temp; // set ptr to next node which is temp
    return temp;      //return node as temp with return type of struct noe*
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node)); // assigne value for head to start the node
    head->data = 45;                                                //assigned value in data part of head structure node
    head->link = NULL;                                              // assigned NULL in link part

    struct node *ptr = head;    //create ptr and assigned the address of head
    ptr = add_at_end(ptr, 100); //calling fucntion for add_at_end with two arrguments
    ptr = add_at_end(ptr, 20);  //
    ptr = add_at_end(ptr, 500); //
    ptr = add_at_end(ptr, 900); //

    ptr = head;         //for traversing the link list again start with head by which we have to assigne the head into ptr
    while (ptr != NULL) //increase ptr until ptr reach last node where NULL is encounter
    {
        printf("%d ", ptr->data); //PRINT data part of each node
        printf("\n");
        ptr = ptr->link;          //access of different node
    }
    free(ptr);
    ptr = NULL;
    return 0;
}