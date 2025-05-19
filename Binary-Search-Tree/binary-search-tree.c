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

    return BST;
}
