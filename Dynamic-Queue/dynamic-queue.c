#include "dynamic-queue.h"

#include <stdio.h>
#include <stdlib.h>

Node * createNode(int value)
{
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

DynamicQueue createDynamicQueue()
{
    DynamicQueue newDQueue;

    newDQueue.bottom = NULL;
    newDQueue.top = NULL;

    return newDQueue;
}

bool isDQueueEmpty(DynamicQueue * dQueue)
{
    return !dQueue->bottom;
}

void push(int value, DynamicQueue * dQueue)
{
    if (isDynamicQueueEmpty(dQueue)) return;

    Node * newNode = createNode(value);

    if (!dQueue->top)
    {
        dQueue->top = newNode;
        dQueue->bottom = newNode;
    }
    else
    {
        dQueue->top->next = newNode;
        dQueue->top = newNode;
    }
}

int popLeft(DynamicQueue * dQueue)
{
    if (isDQueueEmpty(dQueue)) return -1;

    Node * removeElement = dQueue->bottom;

    int value = removeElement->value;

    if (dQueue->top == dQueue->bottom)
    {
        dQueue->top = dQueue->top->next;
    }

    dQueue->bottom = dQueue->bottom->next;

    free(removeElement);

    return value;
}

void cleanDynamicQueue(DynamicQueue * dQueue)
{
    Node * removeElement = NULL;
    Node * cur = dQueue->bottom;

    while(cur)
    {
        removeElement = cur;

        cur = cur->next;

        free(removeElement);
    }

    dQueue->bottom = NULL;
    dQueue->top = NULL;
}
