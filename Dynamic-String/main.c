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
    DynamicString * head2 = createString();

    insertChar('g', head);
    insertChar('a', head);
    insertChar('b', head);

    insertChar('r', head2);
    insertChar('i', head2);
    insertChar('e', head2);
    insertChar('l', head2);

    printString(head);

    printf("\n");
    copyString(head, head2);

    printString(head);

    printf("\nTamanho da string: %d\n", stringLen(head));

    cleanString(head);

    return 0;
}
