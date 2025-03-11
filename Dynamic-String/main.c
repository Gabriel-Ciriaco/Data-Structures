#include "dynamic-string.h"

#include <stdio.h>
#include <stdlib.h>

struct dynamicString {
    char c;
    struct dynamicString * ant;
    struct dynamicString * prox;
};

int main()
{
    DynamicString * head = createString();

    insertChar('g', head);
    insertChar('a', head);
    insertChar('b', head);
    insertChar('r', head);
    insertChar('i', head);
    insertChar('e', head);
    insertChar('l', head);

    printString(head);

    printf("\nTamanho da string: %d\n", stringLen(head));

    cleanString(head);

    return 0;
}
