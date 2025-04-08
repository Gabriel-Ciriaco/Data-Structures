#ifndef CROSSED-LIST_H
#define CROSSED-LIST_H

typedef struct node
{
    int value;
    int row;
    int col;

    struct no * nextRowElement;
    struct no * nextColElement;
} Node;

typedef struct crossedList
{
    int rowSize;
    int colSize;

    Node ** row;
    Node ** col;
} CrossedList;


Node * createNode(int value, int rowPos, int colPos);

CrossedList createCrossedList(int n, int m);

void printCrossedList(CrossedList * cList);

void insertCElement(int element, int rowPos, int colPos, CrossedList * cList);

void removeCElement(int rowPos, int colPos, CrossedList * cList);

void cleanCrossedList(CrossedList * cList);

void sumKtoCrossedList(int k, CrossedList * cList);

#endif // CROSSED-LIST_H
