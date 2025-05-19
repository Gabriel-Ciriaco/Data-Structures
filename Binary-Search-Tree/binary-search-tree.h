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

void insertValueBST(Node * root, int value);

void removeValueBST(Node * root, int value);

int getValueBST(Node * root, int value);


#endif // BINARY-SEARCH-TREE_H
