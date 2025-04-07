#include "crossed-list.h"

Node * createNode(int value, int row, int col)
{
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->value = value;

    newNode->row = row;
    newNode->col = col;

    newNode->next_row = NULL;
    newNode->next_col = NULL;

    return newNode;
}

CrossedList createCrossedList()
{
    CrossedList newList;

    newList.row = NULL;
    newList.col = NULL;

    return newList;
}

