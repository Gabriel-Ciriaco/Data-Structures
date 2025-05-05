#ifndef STATIC-HASH-TABLE_H
#define STATIC-HASH-TABLE_H

#define MAX_HASH_TABLE 100
#define PRIME_NUMBER 211
#define MAX_STR 100

typedef struct node
{
    char value[MAX_STR];
    int nextNode;
} Node;

typedef struct staticHashTable
{
    Node table[MAX_HASH_TABLE];

} StatichHashTable;


Node createNode(char * value);

StatichHashTable createHashTable();

int hash_function(char * key);

int isPosEmpty(int pos, StatichHashTable * sHTable);

void insertValue(char * value, StatichHashTable * sHTable);

void removeValue(char * value, StatichHashTable * sHTable);

#endif // STATIC-HASH-TABLE_H
