#include "crossed-list.h"

Node * createNode(int value, int rowPos, int colPos)
{
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->value = value;

    newNode->row = rowPos;
    newNode->col = colPos;

    newNode->nextRowElement = NULL;
    newNode->nextColElement = NULL;

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
                    int rowPos,
                    int colPos,
                    CrossedList * cList)
{
    Node * newElement = createNode(element, rowPos, colPos);

    // The element at the current row position.
    Node * rowElement = cList->row[rowPos];

    // The element at the current col position.
    Node * colElement = cList->col[colPos];

    // There is no element at the row position.
    if (!rowElement)
    {
        cList->row[rowPos] = newElement;
    }
    else
    {
        Node * lastRowElement = NULL;

        while(rowElement && rowElement->col < colPos)
        {
            lastRowElement = rowElement;

            rowElement = rowElement->nextRowElement;
        }

        if (rowElement)
        {
            if(rowElement->col == colPos)
            {
                printf("\nThere is already an element at this collumn!\n");
            }
            else if(!lastRowElement) // Insertion at the start.
            {
                newElement->nextRowElement = cList->row[rowPos];
                cList->row[rowPos] = newElement;
            }
            else // Insert at the middle.
            {
                newElement->nextRowElement = rowElement;
                lastRow->nextRowElement = newElement;
            }
        }
        else // Insert at the end.
        {
            newElement->nextRowElement = newElement;
        }

    }

    if (!colElement)
    {
        cList->col[colPos] = newElement;
    }
    else
    {
        Node * lastColElement = NULL;

        while(colElement && colElement->row = rowPos)
        {
            lastColElement = colElement;

            lastColElement = colElement->nextColElement;
        }

        if (colElement)
        {

        }


    }

}
