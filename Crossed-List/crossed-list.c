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

CrossedList createCrossedList(int n, int m)
{
    CrossedList newList;

    newList.row = (Node *) malloc(n * sizeof(Node));
    newList.col = (Node *) malloc(m * sizeof(Node));

    for (int i = 0; i < n; i++)
    {
        newList.row[i] = NULL;
    }

    for (int j = 0; i < m; j++)
    {
        newList.col[j] = NULL;
    }

    return newList;
}

void insertCElement(int element,
                    int row,
                    int col,
                    CrossedList * cList)
{

}
