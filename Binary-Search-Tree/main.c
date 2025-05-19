#include "binary-search-tree.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    BST tree = createBST();

    insertValueBST(tree.root, 0);

    return 0;
}
