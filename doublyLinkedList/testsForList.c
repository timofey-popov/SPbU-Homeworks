#include "testsForList.h"

#include <stdlib.h>

bool testForCreateAndDeleteList(void) {
    ErrorCodes errorCode = noErrors;
    ErrorCodes* error = &errorCode;

    LinkedList* testList = createLinkedList(error);
    if (errorCode || testList == NULL) {
        return false;
    }

    deleteLinkedList(testList, error);
    if (errorCode) {
        return false;
    }

    return true;
}

bool testForPushesAndPops(void) {
    ErrorCodes errorCode = noErrors;
    ErrorCodes* error = &errorCode;

    LinkedList* testList = createLinkedList(error);
    if (errorCode || testList == NULL) {
        return false;
    }

    pushToHead(10, testList, error);
    if (errorCode) {
        return false;
    }

    Value testValue = popFromHead(testList, error);
    if (errorCode || testValue != 10) {
        return false;
    }

    pushToTail(-100, testList, error);
    if (errorCode) {
        return false;
    }

    testValue = popFromTail(testList, error);
    if (errorCode || testValue != -100) {
        return false;
    }


    pushToHead(-20, testList, error);
    if (errorCode) {
        return false;
    }
    // -20


    pushToTail(300, testList, error);
    if (errorCode) {
        return false;
    }
    // -20, 300

    pushToHead(90, testList, error);
    if (errorCode) {
        return false;
    }
    // 90, -20, 300

    pushToTail(-2500, testList, error);
    if (errorCode) {
        return false;
    }
    // 90, -20, 300, -2500

    testValue = popFromHead(testList, error);
    if (errorCode || testValue != 90) {
        return false;
    }
    // -20, 300, -2500

    testValue = popFromHead(testList, error);
    if (errorCode || testValue != -20) {
        return false;
    }
    // 300, -2500

    testValue = popFromTail(testList, error);
    if (errorCode || testValue != -2500) {
        return false;
    }
    // 300

    testValue = popFromTail(testList, error);
    if (errorCode || testValue != 300) {
        return false;
    }

    deleteLinkedList(testList, error);
    if (errorCode) {
        return false;
    }

    return true;
}

bool testForRemainingFunctions(void) {
    ErrorCodes errorCode = noErrors;
    ErrorCodes* error = &errorCode;

    LinkedList* testList = createLinkedList(error);
    if (errorCode || testList == NULL) {
        return false;
    }

    pushToHead(10, testList, error);
    if (errorCode) {
        return false;
    }

    Value testValue = getNthValue(testList, 1, error);
    if (errorCode || testValue != 10) {
        return false;
    }

    pushToHead(30, testList, error);
    pushToHead(50, testList, error);
    // 50, 30, 10

    testValue = getNthValue(testList, 1, error);
    if (errorCode || testValue != 50) {
        return false;
    }

    testValue = getNthValue(testList, 3, error);
    if (errorCode || testValue != 10) {
        return false;
    }

    insertNthElement(100, 3, testList, error);
    if (errorCode || getNthValue(testList, 3, error) != 100 || getNthValue(testList, 4, error) != 10) {
        return false;
    }
    // 50, 30, 100, 10

    insertNthElement(200, 1, testList, error);
    if (errorCode) {
        return false;
    }
    // 200, 50, 30, 100, 10

    testValue = popNthElement(testList, 1, error);
    if (errorCode || testValue != 200 || getNthValue(testList, 1, error) != 50) {
        return false;
    }
    // 50, 30, 100, 10

    testValue = popNthElement(testList, 4, error);
    if (errorCode || testValue != 10 || getNthValue(testList, 3, error) != 100) {
        return false;
    }
    // 50, 30, 100

    testValue = popNthElement(testList, 2, error);
    if (errorCode || testValue != 30 || getNthValue(testList, 1, error) != 50) {
        return false;
    }
    // 50, 100

    clearList(testList, error);
    if (errorCode) {
        return false;
    }

    bool check = isEmpty(testList, error);
    if (!check || errorCode) {
        return false;
    }

    pushToHead(10, testList, error);

    check = isEmpty(testList, error);
    if (check || errorCode) {
        return false;
    }

    deleteLinkedList(testList, error);
    if (errorCode) {
        return false;
    }

    return true;
}
