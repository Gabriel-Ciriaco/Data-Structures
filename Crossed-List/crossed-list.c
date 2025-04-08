#include "crossed-list.h"

#include <stdio.h>
#include <stdlib.h>

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

    for (int j = 0; j < m; j++)
    {
        newList.col[j] = NULL;
    }

    return newList;
}

void printCrossedList(CrossedList * cList)
{
    Node * curRowElement = NULL;

    printf("\n");
    for (int i = 0; i < cList->rowSize; i++)
    {
        curRowElement = cList->row[i];
        printf("\n");

        for (int j = 0; j < cList->colSize; j++)
        {
            if (curRowElement && curRowElement->col == j)
            {
                printf(" %d", curRowElement->value);

                curRowElement = curRowElement->nextRowElement;
            }
            else
            {
                printf(" 0"); // We print 0 as if it was a null value.
            }
        }
    }
    printf("\n");
}

void insertCElement(int element,
                    int rowPos,
                    int colPos,
                    CrossedList * cList)
{
    Node * newElement = createNode(element, rowPos, colPos);

    // The first element at the current row position.
    Node * firstRowElement = cList->row[rowPos];

    // The element at the current col position.
    Node * firstColElement = cList->col[colPos];

    // If we don't have any element at the row.
    if (!firstRowElement)
    {
        cList->row[rowPos] = newElement;
    }
    else
    {
        Node * lastRowElement = NULL;

        while (firstRowElement && firstRowElement->col < colPos)
        {
            lastRowElement = firstRowElement;

            firstRowElement = firstRowElement->nextRowElement;
        }

        if(firstRowElement)
        {
            if (firstRowElement->col == colPos)
            {
                printf("\nThere is already an element at this column position!\n");
            }
            else if(!lastRowElement) // Insert at start of the row.
            {
                newElement->nextRowElement = firstRowElement;

                // New element becomes the first element of the row.
                cList->row[rowPos] = newElement;
            }
            else // Insert at middle of the row.
            {
                lastRowElement->nextRowElement = newElement;
                newElement->nextRowElement = firstRowElement;
            }
        }
        else // Insert at the end of the row.
        {
            lastRowElement->nextRowElement = newElement;
        }
    }

    // If there is no element at the column.
    if (!firstColElement)
    {
        cList->col[colPos] = newElement;
    }
    else // There is an element at the column.
    {
        Node * lastColElement = NULL;

        while (firstColElement && firstColElement->row < rowPos)
        {
            lastColElement = firstColElement;

            firstColElement = firstColElement->nextColElement;
        }

        if(firstColElement)
        {
            if (firstColElement->row == rowPos)
            {
                printf("\nThere is already an element at this row position!\n");
            }
            else if (!lastColElement) // Insert at start of the row.
            {
                newElement->nextColElement = firstColElement;

                // New Element becomes the first element of the col.
                cList->col[colPos] = newElement;
            }
            else // Insert at the middle of the row.
            {
                lastColElement->nextColElement = newElement;
                newElement->nextColElement = firstColElement;
            }

        }
        else // Insert at the end of the col.
        {
            lastColElement->nextColElement = newElement;
        }
    }
}

void removeCElement(int rowPos, int colPos, CrossedList * cList)
{
    Node * removeElement = cList->row[rowPos];
    Node * lastRowElement = NULL;

    while(removeElement && removeElement->col < colPos)
    {
        lastRowElement = removeElement;

        removeElement = removeElement->nextRowElement;
    }


    // We found the element we are looking for.
    if (removeElement && removeElement->col == colPos)
    {
        // If this is the first element of the row.
        if (!lastRowElement)
        {
            cList->row[rowPos] = removeElement->nextRowElement;
        }
        else
        {
            lastRowElement->nextRowElement = removeElement->nextRowElement;
        }

        // If this is the first element of our column.
        if(cList->col[colPos] == removeElement)
        {
            cList->col[colPos] = removeElement->nextColElement;
        }
        else
        {
            Node * curColElement = cList->col[colPos];
            Node * lastColElement = NULL;

            while (curColElement != removeElement)
            {
                lastColElement = curColElement;

                curColElement = curColElement->nextColElement;
            }

            lastColElement->nextColElement = curColElement->nextColElement;
        }

        free(removeElement);

        // Prevent access to deleted memory.
        removeElement = NULL;
    }
    else
    {
        printf("\nThere is no element at this position.\n");
    }
}

void cleanCrossedList(CrossedList * cList)
{
    Node * curRowElement = NULL;
    Node * lastRowElement = NULL;

    for (int i = 0; i < cList->rowSize; i++)
    {
        // Get the first element of the row.
        curRowElement = cList->row[i];

        while(curRowElement)
        {
            lastRowElement = curRowElement;
            curRowElement = curRowElement->nextRowElement;

            free(lastRowElement);

            lastRowElement = NULL;
        }

        cList->row[i] = NULL;
    }

    // Prevent to access deleted memory.
    for (int j = 0; j < cList->colSize; j++)
    {
        cList->col[j] = NULL;
    }

    free(cList->row);
    free(cList->col);

    // Prevent access to deleted memory;
    cList->row = NULL;
    cList->col = NULL;
}

void sumKtoCrossedList(int k, CrossedList * cList)
{
    Node * curRowElement = NULL;

    for (int i = 0; i < cList->rowSize; i++)
    {
        // Get the first element of the row.
        curRowElement = cList->row[i];

        while (curRowElement)
        {
            curRowElement->value += k;

            curRowElement = curRowElement->nextRowElement;
        }
    }
}
