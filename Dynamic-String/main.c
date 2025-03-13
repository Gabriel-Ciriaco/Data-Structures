#include "dynamic-string.h"

#include <stdio.h>
#include <stdlib.h>


int main()
{
    DynamicString strDim = createString();
    DynamicString strDim2 = createString();
    DynamicString strDim3 = createString();

    insertChar('g', &strDim);
    insertChar('a', &strDim);
    insertChar('b', &strDim);

    insertChar('r', &strDim2);
    insertChar('i', &strDim2);
    insertChar('e', &strDim2);
    insertChar('l', &strDim2);

    concatString(&strDim3, &strDim2, &strDim);

    printString(&strDim3);

    removeChars(&strDim3, 2, 1);

    printf("\n");
    printString(&strDim3);

    cleanString(&strDim);
    cleanString(&strDim2);
    cleanString(&strDim3);

    return 0;
}
