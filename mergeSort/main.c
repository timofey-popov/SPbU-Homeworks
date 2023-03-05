#include "mergeSort.h"
#include "tests.h"

#include <stdio.h>

int main(void) {
    if (!testForMergeSort()) {
        printf("Tests failed.\n\n");
        return -1;
    }
    else {
        printf("*tests passed*\n\n");
    }

    ListErrors errorCode = noErrorsInList;

    List* initialList = createList(&errorCode);
    addElement(0, initialList, &errorCode);
    addElement(-96, initialList, &errorCode);
    addElement(-150, initialList, &errorCode);
    addElement(46, initialList, &errorCode);
    addElement(-3, initialList, &errorCode);
    addElement(95, initialList, &errorCode);
    addElement(3, initialList, &errorCode);
    addElement(-96, initialList, &errorCode);

    List* result = mergeSort(initialList, &errorCode);

    printf("Here's the sorted list:\n");
    printList(result, &errorCode);

    deleteList(initialList, &errorCode);
    deleteList(result, &errorCode);
    if (errorCode) {
        printf("An error occured: %d", errorCode);
        return errorCode;
    }

    return 0;
}
