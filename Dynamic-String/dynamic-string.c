#include "dynamic-string.h"
#include <stdio.h>
#include <stdlib.h>


Node * createNode(char c)
{
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->c = c;

    newNode->prev = NULL;
    newNode->next = NULL;
}

DynamicString createString()
{
    DynamicString strDim;

    strDim.head = NULL;
    strDim.tail = NULL;

    strDim.length = 0;

    return strDim;
}

void cleanString(DynamicString * strDim)
{
    if (!strDim->head) return;

    Node * cur = strDim->head;
    Node * prev;

    while (cur)
    {
        prev = cur;

        cur = cur->next;

        free(prev);
    }

}

void printString(DynamicString * strDim)
{
    if (!strDim->head) return;

    Node * cur = strDim->head;

    while (cur)
    {
        printf("%c", cur->c);

        cur = cur->next;
    }

}

int stringLen(DynamicString * strDim)
{
    return strDim->length;
}

void insertChar(char c, DynamicString * strDim)
{
    Node * newNode = createNode(c);

    if (!strDim->head)
    {
        strDim->head = newNode;
        strDim->tail = newNode;
    }
    else
    {
        newNode->prev = strDim->tail;

        (strDim->tail)->next = newNode;

        strDim->tail = newNode;
    }

    strDim->length++;
}

void copyString(DynamicString * output, DynamicString * input)
{
    Node * cur = input->head;
    Node * out = output->head;

    while (cur && out)
    {
        out->c = cur->c;

        cur = cur->next;
        out = out->next;
    }

    while (cur)
    {

    }

}
