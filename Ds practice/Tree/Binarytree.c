//binarytree.c

#include <stdio.h>
#include <stdlib.h>

struct node
{
   struct node *left;
   int data;
   struct node *right; 
};

struct node  *getNewNode(int data)
{
    struct node *NN = (struct node*)malloc(sizeof(struct node));
    NN->data = data;
    NN->left = NN->right = NULL;
    return NN;
}

struct node* Inset(struct node *root, int data)
{
    if(root == NULL)
    {
        root = getNewNode(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = Inset(root->left, data);
    }
    else 
    {
        root->right = Inset(root->right, data);
    }
    return root;
}

void preOrderTraversal(struct node* root)
{
    if(root != NULL)
    {
        printf("%d\t", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main()
{
    struct node *root = NULL;   //creating an empty tree

    root = Inset(root, 10);
    root = Inset(root, 15);
    root = Inset(root, 5);
    root = Inset(root, 25);
    root = Inset(root, 16);
    root = Inset(root, 75);
    root = Inset(root, 4);
    root = Inset(root, 2);

    preOrderTraversal(root);
    return 0;
}