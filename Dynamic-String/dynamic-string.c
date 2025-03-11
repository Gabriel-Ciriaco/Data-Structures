#include "dynamic-string.h"
#include <stdio.h>
#include <stdlib.h>


struct dynamicString {
    char c;
    struct dynamicString * ant;
    struct dynamicString * prox;
};


DynamicString * createString()
{
    DynamicString * strDim = (DynamicString * ) malloc(sizeof(DynamicString));

    strDim->ant = NULL;
    strDim->prox = NULL;

    return strDim;
}

void cleanString(DynamicString * strDim)
{
    DynamicString * atual = strDim->prox;
    DynamicString * anterior = strDim;

    while (atual)
    {
        anterior = atual;

        free(anterior);

        atual = atual->prox;
    }
}

void printString(DynamicString * strDim)
{
    DynamicString * atual = strDim->prox;

    while (atual)
    {
        printf("%c\n", atual->c);

        atual = atual->prox;
    }
}

int stringLen(DynamicString * strDim)
{
    int counter = 0;

    DynamicString * atual = strDim->prox;

    while (atual)
    {
        counter++;
        atual = atual->prox;
    }

    return counter;
}

void insertChar(char c, DynamicString * strDim)
{
    DynamicString * atual = strDim->prox;
    DynamicString * anterior = strDim;

    while (atual)
    {
        anterior = atual;
        atual = atual->prox;
    }

    atual = createString();

    atual->c = c;

    atual->ant = anterior;
    anterior->prox = atual;
}
