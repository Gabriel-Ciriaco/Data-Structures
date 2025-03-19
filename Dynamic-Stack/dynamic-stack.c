#include "dynamic-stack.h"

#include <stdlib.h>
#include <stdbool.h>


Node * createNode(int value)
{
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

DynamicStack createDynamicStack()
{
    DynamicStack newStack;

    newStack.top = NULL;

    return newStack;
}

bool isStackEmpty(DynamicStack * dStack)
{
    return !(dStack->top);
}

void push(int value, DynamicStack * dStack)
{
    Node * newValue = createNode(value);

    if (!dStack->top)
    {
        dStack->top = newValue;
    }
    else
    {
        Node * cur = dStack->top;

        newValue->next = cur;

        dStack->top = newValue;
    }
}

int pop(DynamicStack * dStack)
{
    if(!isStackEmpty(dStack))
    {
        Node * cur = dStack->top;

        dStack->top = cur->next;

        int topValue = cur->value;

        free(cur);

        return topValue;
    }
}

void cleanStack(DynamicStack * dStack)
{
    if (!dStack->top) return;

    while (dStack->top)
    {
        pop(dStack);
    }
}
