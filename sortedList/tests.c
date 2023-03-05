#include "tests.h"
#include "sortedList.h"
#include <stdlib.h>

bool testForCreateAndDeleteList(void) {
    ListErrors testErrorCode = noErrors;

    SortedList* testList = createList(&testErrorCode);
    if (testErrorCode || (testList == NULL)) {
        return false;
    }

    deleteList(testList, &testErrorCode);
    
    return !testErrorCode;
}

bool testForAddAndDeleteValue(void) {
    ListErrors testErrorCode = noErrors;

    SortedList* testList = createList(&testErrorCode);
    if (testErrorCode || (testList == NULL)) {
        return false;
    }

    deleteFromList(100, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(1, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(50, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(1, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(-6, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(15, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(3, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(15, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(20, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(-6, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(20, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteList(testList, &testErrorCode);

    return !testErrorCode;
}