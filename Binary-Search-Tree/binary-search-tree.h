#ifndef BINARY-SEARCH-TREE_H
#define BINARY-SEARCH-TREE_H

typedef struct node
{
    int value;

    struct node * left;
    struct node * right;
} Node;

typedef struct bst
{
    Node * root;
} BST;


Node * createNode(int value);

BST createBST();

Node * insertValueBST(Node * root, int value);

Node * removeValueBST(Node * root, int value);

int getValueBST(Node * root, int value);

void printPreOrder(Node * root);

void printInOrder(Node * root);

void printPostOrder(Node * root);


#endif // BINARY-SEARCH-TREE_H
