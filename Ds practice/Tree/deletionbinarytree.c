//deletionbinarytree.c
//Write a program to implement deletion & display of Binary Trees.

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
struct node *FindMin(struct node *root)
{
    if (root == NULL || root ->left == NULL)
    {
        return root;
    }
    else
    {
        return FindMin(root->left);
    }
}
////////////////////////////////////////////////////////////////
struct node *deletion(struct node *root, int  data)
{
    if (root == NULL)
    {
        printf("\nValue not found");
        return root;
    }
    else if (data < root->data)
    {
        root->left = deletion(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deletion(root->right, data);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)   //No child
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)    // 1 child
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
        }
        else if (root->right == NULL)   //1 child
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }
        else    // 2 childern
        {
            struct node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
    }
    return root;
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

        case 5: printf("\nEnter the delete data: ");
            scanf("%d", &data);
            root = deletion(root, data);
            break;
        }
    } while (option != 6);
    
}