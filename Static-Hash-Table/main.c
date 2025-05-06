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
    printf("%d\n", table.table[42].nextNode);
    insertValue("goat", &table);
    printf("%d\n", table.table[42].nextNode);
    insertValue("goat", &table);
    printf("%d\n", table.table[43].nextNode);

    removeValue("goat", &table);

    printf("%d", table.table[42].nextNode);

    return 0;
}
