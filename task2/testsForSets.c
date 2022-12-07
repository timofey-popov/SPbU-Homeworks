#include "testsForSets.h"

#include <stdlib.h>

bool testForCreateAndDeleteSet(void) {
    ErrorCodesForSet errorCode = noErrors;
    ErrorCodesForSet* error = &errorCode;

    Set* testSet1 = createSet(10, error);
    if (testSet1 == NULL || errorCode) {
        freeSet(testSet1, error);
        return false;
    }

    Set* testSet2 = createSet(-500, error);
    if (testSet2 == NULL || errorCode) {
        freeSet(testSet1, error);
        freeSet(testSet2, error);
        return false;
    }

    freeSet(testSet1, error);
    if (errorCode) {
        freeSet(testSet2, error);
        return false;
    }

    freeSet(testSet2, error);
    if (errorCode) {
        return false;
    }

    return true;
}

bool testForIsTheSameSetAndUnite(void) {
    ErrorCodesForSet errorCode = noErrors;
    ErrorCodesForSet* error = &errorCode;

    Set* testSet1 = createSet(100, error);
    if (testSet1 == NULL || errorCode) {
        freeSet(testSet1, error);
        return false;
    }

    Set* testSet2 = createSet(300, error);
    if (testSet2 == NULL || errorCode) {
        freeSet(testSet1, error);
        freeSet(testSet2, error);
        return false;
    }

    bool check = isTheSameSet(testSet1, testSet2, error);
    if (check || errorCode) {
        freeSet(testSet1, error);
        freeSet(testSet2, error);
        return false;
    }

    unite(testSet1, testSet2, error);
    if (errorCode || !isTheSameSet(testSet1, testSet2, error)) {
        freeSet(testSet1, error);
        freeSet(testSet2, error);
        return false;
    }

    freeSet(testSet1, error);

    return true;
}
