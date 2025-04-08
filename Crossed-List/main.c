#include "crossed-list.h"

#include <stdio.h>
#include <stdlib.h>


int main()
{
    CrossedList cList = createCrossedList(5, 5);

    insertCElement(1, 0, 1, &cList);
    insertCElement(2, 0, 0, &cList);
    insertCElement(3, 0, 2, &cList);
    insertCElement(4, 1, 1, &cList);
    insertCElement(5, 1, 2, &cList);
    insertCElement(6, 1, 0, &cList);
    insertCElement(7, 4, 1, &cList);



    printCrossedList(&cList);

    removeCElement(1, 1, &cList);

    printCrossedList(&cList);

    sumKtoCrossedList(10, &cList);

    printCrossedList(&cList);

    cleanCrossedList(&cList);


    return 0;
}
