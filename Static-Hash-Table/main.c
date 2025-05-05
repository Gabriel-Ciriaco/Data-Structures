#include "static-hash-table.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hash value: %d\n", hash_function("goat"));
    printf("Hash value: %d\n", hash_function("test"));
    printf("Hash value: %d\n", hash_function("lucas"));

    StatichHashTable table = createHashTable();

    insertValue("goat", &table);

    printf("%s", table.table[0]->value);

    return 0;
}
