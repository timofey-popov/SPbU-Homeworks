#include "task2.h"

#include "testsForSets.h"
#include <stdio.h>

int main(void) {
    if (!testForCreateAndDeleteSet() || !testForIsTheSameSetAndUnite()) {
        printf("Tests failed with: %d, %d", testForCreateAndDeleteSet(), testForIsTheSameSetAndUnite());
        return -1;
    }
    else {
        printf("*test passed*\n");
    }

    ErrorCodesForSet errorCode = noErrors;
    ErrorCodesForSet* error = &errorCode;

    Set* a = createSet(10, error);
    if (errorCode) {
        ErrorCodesForSet currentError = errorCode;
        freeSet(a, error);
        return currentError;
    }

    Set* b = createSet(20, error);
    if (errorCode) {
        ErrorCodesForSet currentError = errorCode;
        freeSet(a, error);
        freeSet(b, error);
        return currentError;
    }

    printf("%d\n", isTheSameSet(a, b, error));
    if (errorCode) {
        ErrorCodesForSet currentError = errorCode;
        freeSet(a, error);
        freeSet(b, error);
        return currentError;
    }

    Set* c = unite(a, b, error);
    if (errorCode) {
        ErrorCodesForSet currentError = errorCode;
        freeSet(a, error);
        freeSet(b, error);

        return currentError;
    }

    printf("%d\n", isTheSameSet(a, b, error));
    if (errorCode) {
        ErrorCodesForSet currentError = errorCode;
        freeSet(a, error);
        freeSet(b, error);
        return currentError;
    }
}