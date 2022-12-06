#include "testsForStack.h"

#include <stdlib.h>

bool testForCreateAndDeleteStack(void) {
    ErrorCodes errorCode = noErrors;

    Stack* testStack = createStack(&errorCode);
    if (testStack == NULL || errorCode) {
        deleteStack(testStack, &errorCode);
        return false;
    }

    deleteStack(testStack, &errorCode);
    if (errorCode) {
        return false;
    }

    // «десь и далее: намеренно не сокращаю код до "return !errorCode;", потому что хочу сохран€ть логику изложени€:
    // ѕроверка - если плохо - false, проверка - если плохо - false, а в конце, если всЄ хорошо - true.
    return true;
}

bool testForPushAndPop(void) {
    ErrorCodes errorCode = noErrors;

    Stack* testStack = createStack(&errorCode);
    if (testStack == NULL || errorCode) {
        return false;
    }

    push(10, testStack, &errorCode);
    if (errorCode) {
        deleteStack(testStack, &errorCode);
        return false;
    }

    Value testValue = pop(testStack, &errorCode);
    if (errorCode || testValue != 10) {
        deleteStack(testStack, &errorCode);
        return false;
    }

    deleteStack(testStack, &errorCode);
    if (errorCode) {
        return false;
    }

    return true;
}

bool testForClearAndIsEmpty(void) {
    ErrorCodes errorCode = noErrors;

    Stack* testStack = createStack(&errorCode);
    if (testStack == NULL || errorCode) {
        return false;
    }

    bool emptynessTest1 = isEmpty(testStack, &errorCode);
    if (errorCode) {
        deleteStack(testStack, &errorCode);
        return false;
    }

    push(10, testStack, &errorCode);
    push(20, testStack, &errorCode);

    bool emptynessTest2 = isEmpty(testStack, &errorCode);
    if (errorCode) {
        deleteStack(testStack, &errorCode);
        return false;
    }

    clear(testStack, &errorCode);
    if (errorCode) {
        deleteStack(testStack, &errorCode);
        return false;
    }

    bool emptynessTest3 = isEmpty(testStack, &errorCode);

    if (errorCode || !emptynessTest1 || emptynessTest2 || !emptynessTest3) {
        deleteStack(testStack, &errorCode);
        return false;
    }

    deleteStack(testStack, &errorCode);
    return true;
}
