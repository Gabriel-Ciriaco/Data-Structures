#include "static-hash-table.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hash value: %d\n", hash_function("goat"));
    printf("Hash value: %d\n", hash_function("goAt"));
    printf("Hash value: %d\n", hash_function("lucas"));

    StatichHashTable sHTable = createHashTable();

    insertValue("goat", "igor", &sHTable);
    insertValue("goat", "gabriel", &sHTable);
    insertValue("goat", "carol", &sHTable);


    printf("%s %s %s\n", sHTable.table[42].value, sHTable.table[43].value, sHTable.table[44].value);
    printf("%d %d %d\n", sHTable.table[42].nextNode, sHTable.table[43].nextNode, sHTable.table[44].nextNode);

    removeValue("goat", "gabriel", &sHTable);

    printf("%s %s %s\n", sHTable.table[42].value, sHTable.table[43].value, sHTable.table[44].value);
    printf("%d %d %d\n", sHTable.table[42].nextNode, sHTable.table[43].nextNode, sHTable.table[44].nextNode);

    removeValue("goat", "igor", &sHTable);

    printf("%s %s %s\n", sHTable.table[42].value, sHTable.table[43].value, sHTable.table[44].value);
    printf("%d %d %d\n", sHTable.table[42].nextNode, sHTable.table[43].nextNode, sHTable.table[44].nextNode);

    removeValue("goat", "carol", &sHTable);

    printf("%s %s %s\n", sHTable.table[42].value, sHTable.table[43].value, sHTable.table[44].value);
    printf("%d %d %d\n", sHTable.table[42].nextNode, sHTable.table[43].nextNode, sHTable.table[44].nextNode);


    return 0;
}
