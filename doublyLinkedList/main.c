#include "doublyLinkedList.h"
#include "testsForList.h"

#include <stdio.h>

int main(void) {
    if (!testForCreateAndDeleteList() || !testForPushesAndPops() || !testForRemainingFunctions()) {
        printf("Tests failed with following output: %d, %d, %d\n", testForCreateAndDeleteList(), testForPushesAndPops(), testForRemainingFunctions());
        return -1;
    }
    else {
        printf("*test passed*\n\n");
    }

    ErrorCodes errorCode = noErrors;

    LinkedList* myList = createLinkedList(&errorCode);
    if (errorCode) {
        return errorCode;
    }

    pushToTail(10, myList, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    printf("%d\n", getNthValue(myList, 1, &errorCode));
    if (errorCode) {
        return errorCode;
    }

    deleteLinkedList(myList, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    return 0;
}
