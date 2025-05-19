#include "binary-search-tree.h"

#include <stdio.h>
#include <stdlib.h>

Node * createNode(int value)
{
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->value = value;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BST createBST()
{
    BST newTree;

    newTree.root = NULL;

    return newTree;
}

Node * insertValueBST(Node * root, int value)
{
    if (!root)
    {
        return createNode(value);
    }

    if (value < root->value)
    {
        root->left = insertValueBST(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insertValueBST(root->right, value);
    }
    else
    {
        printf("\nThe value %d already exists in the tree!\n", value);
    }

    return root;
}

Node * removeValueBST(Node * root, int value)
{
    if (!root) return root;

    if (value < root->left)
    {

    }
}

void printPreOrder(Node * root)
{
    if (!root) return;

    printf("%d ", root->value);

    printPreOrder(root->left);

    printPreOrder(root->right);
}

void printInOrder(Node * root)
{
    if (!root) return;

    printInOrder(root->left);

    printf("%d ", root->value);

    printInOrder(root->right);
}

void printPostOrder(Node * root)
{
    if (!root) return;

    printPostOrder(root->left);

    printPostOrder(root->right);

    printf("%d ", root->value);
}
