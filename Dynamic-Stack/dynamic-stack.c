#include "dynamic-stack.h"

#include <stdlib.h>


Node * createNode(int value)
{
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

void createDynamicStack()
{
    DynamicStack newStack;

    newStack->top = NULL;

    return newStack;
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

void pop(DynamicStack * dStack)
{
    if (!dStack->top)
    {
        printf("\nThe Dynamic Stack is empty!\n");
    }
    else
    {
        Node * cur = dStack->top;

        dStack->top = cur->next;

        free(cur);
    }
}

