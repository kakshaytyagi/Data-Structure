//treebinary.c
//Write a program to implement creation, insertion & display of Binary Trees.

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *left;
    int data;
    struct node *right;
};
////////////////////////////////////////////////////////////////
struct node  *getNewNode(int data)
{
    struct node *NN = (struct node*)malloc(sizeof(struct node));
    NN->data = data;
    NN->left = NN->right = NULL;
    return NN;
}
////////////////////////////////////////////////////////////////
struct node* Insertion(struct node* root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = Insertion(root->left, data);
    }
    else
    {
        root->right = Insertion(root->right, data);
    }
    return root;
        
}
////////////////////////////////////////////////////////////////
void preOrderTraversal(struct node* root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
////////////////////////////////////////////////////////////////
void postOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d\t", root->data);
    }
}
////////////////////////////////////////////////////////////////
void inOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d\t", root->data);
        inOrderTraversal(root->right);
    }
}
////////////////////////////////////////////////////////////////
int main()
{
    struct node *root = NULL;
    int option, data;

    do
    {
        printf("\nEnter the choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            root = Insertion(root, data);
            break;
        
        case 2: preOrderTraversal(root);
            break;

        case 3: postOrderTraversal(root);
            break;

        case 4: inOrderTraversal(root);
            break;
        }
    } while (option != 5);
    
}