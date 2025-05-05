#include "static-hash-table.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hash value: %d\n", hash_function("goat"));
    printf("Hash value: %d\n", hash_function("goAt"));
    printf("Hash value: %d\n", hash_function("lucas"));

    StatichHashTable table = createHashTable();

    insertValue("goat", &table);
    insertValue("goat", &table);

    removeValue("goat", &table);

    printf("%s %d %d", table.table[42].value, table.table[42].nextNode, table.table[table.table[42].nextNode].nextNode);

    return 0;
}
