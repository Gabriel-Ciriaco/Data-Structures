#ifndef CROSSED-LIST_H
#define CROSSED-LIST_H

typedef struct node
{
    int value;
    int row;
    int col;

    struct no * next_row;
    struct no * next_col;
} Node;

typedef struct crossedList
{
    Node * row;
    Node * col;
} CrossedList;


Node * createNode(int value, int row, int col);

CrossedList createCrossedList(int n, int m);

void printCrossedList(CrossedList * cList);

void insertCElement(int element, int row, int col, CrossedList * cList);

void removeCElement(int element, CrossedList * cList);

#endif // CROSSED-LIST_H
