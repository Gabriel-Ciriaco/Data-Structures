#ifndef STATIC-HASH-TABLE_H
#define STATIC-HASH-TABLE_H

#define MAX_HASH_TABLE 100
#define PRIME_NUMBER 211
#define MAX_STR 100

#define NULL_VALUE ""
#define TERMINAL_NODE -1

typedef struct node
{
    char key[MAX_STR];
    char value[MAX_STR];

    int nextNode;
} Node;

typedef struct staticHashTable
{
    Node table[MAX_HASH_TABLE];

} StatichHashTable;


Node createNode(char * key, char * value);

StatichHashTable createHashTable();

int hash_function(char * key);

void insertValue(char * key, char * value, StatichHashTable * sHTable);

void removeValue(char * key, char * value, StatichHashTable * sHTable);

#endif // STATIC-HASH-TABLE_H
