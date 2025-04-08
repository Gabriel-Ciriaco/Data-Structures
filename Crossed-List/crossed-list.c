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

    newList.rowSize = n;
    newList.colSize = m;

    newList.row = (Node **) malloc(n * sizeof(Node *));
    newList.col = (Node **) malloc(m * sizeof(Node *));

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

void printCrossedList(CrossedList * cList)
{
    Node * cur = NULL;

    for (int i = 0; i < cList.rowSize; i++)
    {
        cur = cList->row[i];
        printf("\n");

        for (int j = 0; j < cList.colSize; j++)
        {
            if(cur && cur->col == j)
            {
                printf(" %d", cur->value);
                cur = cur->nextColElement;
            }
            else
            {
                printf(" NULL"); // There is no element there.
            }
        }
    }
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
            lastRowElement->nextRowElement = newElement;
        }

    }

    if (!colElement)
    {
        cList->col[colPos] = newElement;
    }
    else
    {
        Node * lastColElement = NULL;

        while(colElement && colElement->row < rowPos)
        {
            lastColElement = colElement;

            lastColElement = colElement->nextColElement;
        }

        if (colElement)
        {
            if (colElement->row == rowPos)
            {
                printf("\nThere is already an element at this row!\n");
            }
            else if (!lastColElement) // Insert at the start.
            {
                newElement->nextColElement = cList->col[colPos];
                cList->col[colPos] = newElement;
            }
            else // Insert at the middle.
            {
                newElement->nextColElement = colElement;
                lastColElement->nextColElement = newElement;
            }
        }
        else // Insert at the end.
        {
            lastColElement->nextColElement = newElement;
        }
    }

}

void cleanCrossedList(CrossedList * cList)
{
    Node * cur = NULL;

    for (int i = 0; i < cList.rowSize; i++)
    {
        for (int j = 0; j < cList.colSize; j++)
        {
            if (cur && cur->col == j)
            {
                free(cList->col[j]);

                // Prevent to access a deleted memory
                cList->col[j] = NULL;

                cur = cur->nextColElement;
            }
        }

        free(cList->row[i]);

        // Prevent to access a deleted memory.
        cList->row[i] == NULL;
    }

    free(cList->row);
    free(cList->col);

    // Prevent access to a deleted memory.
    cList->row = NULL;
    cList->col = NULL;
}
