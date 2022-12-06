#include "testsForQueue.h"

#include <stdlib.h>

bool testForCreateAndDeleteQueue(void) {
    ErrorCodes errorCode = noErrors;

    Queue* testQueue = NULL;

    testQueue = createQueue(&errorCode);
    if (testQueue == NULL || errorCode) {
        return false;
    }

    deleteQueue(testQueue, &errorCode);
    if (errorCode) {
        return false;
    }

    return true;
}

bool testForEnqueueAndDequeue(void) {
    ErrorCodes errorCode = noErrors;

    Queue* testQueue = createQueue(&errorCode);
    if (testQueue == NULL || errorCode) {
        return false;
    }

    enqueue(10, testQueue, &errorCode);
    if (errorCode) {
        return false;
    }

    enqueue(20, testQueue, &errorCode);
    if (errorCode) {
        return false;
    }

    Value testValue = dequeue(testQueue, &errorCode);
    if (errorCode || testValue != 10) {
        return false;
    }

    deleteQueue(testQueue, &errorCode);
    if (errorCode) {
        return false;
    }

    return true;
}

bool testForClearAndIsEmpty(void) {
    ErrorCodes errorCode = noErrors;

    Queue* testQueue = createQueue(&errorCode);
    if (testQueue == NULL || errorCode) {
        return false;
    }

    bool emptynessTest1 = isEmpty(testQueue, &errorCode);
    if (errorCode) {
        return false;
    }

    enqueue(10, testQueue, &errorCode);
    enqueue(20, testQueue, &errorCode);

    bool emptynessTest2 = isEmpty(testQueue, &errorCode);
    if (errorCode) {
        return false;
    }

    clear(testQueue, &errorCode);
    if (errorCode) {
        return false;
    }

    bool emptynessTest3 = isEmpty(testQueue, &errorCode);

    if (errorCode || !emptynessTest1 || emptynessTest2 || !emptynessTest3) {
        return false;
    }

    return true;
}
