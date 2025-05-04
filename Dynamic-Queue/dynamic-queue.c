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

isDynamic
