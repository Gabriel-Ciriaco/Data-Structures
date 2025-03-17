#include "dynamic-string.h"

#include <stdio.h>
#include <stdlib.h>


int main()
{
    DynamicString strDim = createString();
    DynamicString strDim2 = createString();
    DynamicString strDim3 = createString();
    DynamicString strDim4 = createString();

    insertChar('g', &strDim);
    insertChar('a', &strDim);
    insertChar('b', &strDim);

    insertChar('r', &strDim2);
    insertChar('i', &strDim2);
    insertChar('e', &strDim2);
    insertChar('l', &strDim2);

    concatString(&strDim3, &strDim2, &strDim);

    printf("\nStrdim3: ");
    printString(&strDim3);

    concatString(&strDim4, &strDim2, &strDim);

    printf("\nStrdim4: ");
    printString(&strDim4);

    printf("\nstrDim3 eh igual a strDim4: %s\n", strIsEqual(&strDim3, &strDim4) ? "true" : "false");

    printf("\nTamanho da String: %d\n", stringLen(&strDim3));

    printf("\nStrdim2 em strdim3 posicao: %d\n", searchString(&strDim3, &strDim4));

    removeChars(&strDim3, 3, 4);

    printf("\n");
    printString(&strDim3);
    printf("\nTamanho da String: %d\n", stringLen(&strDim3));

    cleanString(&strDim);
    cleanString(&strDim2);
    cleanString(&strDim3);

    return 0;
}
