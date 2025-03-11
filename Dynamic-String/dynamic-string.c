#include "dynamic-string.h"
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
    DynamicString * anterior;

    while (atual)
    {
        anterior = atual;

        free(anterior);

        atual = atual->prox;
    }
}
