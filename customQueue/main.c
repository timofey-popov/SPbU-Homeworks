#include "customQueue.h"

#include "testsForQueue.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    if (!testForCreateAndDeleteQueue() || !testForEnqueueAndDequeue() || !testForClearAndIsEmpty()) {
        printf("Tests failed.\n");
        return -1;
    }
    else {
        printf("*tests passed*\n\n");
    }

    ErrorCodes errorCode = noErrors;

    Queue* queue = createQueue(&errorCode);
    if (errorCode) {
        return errorCode;
    }

    enqueue(5, queue, &errorCode);
    if (errorCode) {
        deleteQueue(queue, &errorCode);
        return errorCode;
    }

    dequeue(queue, &errorCode);
    if (errorCode) {
        deleteQueue(queue, &errorCode);
        return errorCode;
    }

    enqueue(100, queue, &errorCode);
    if (errorCode) {
        deleteQueue(queue, &errorCode);
        return errorCode;
    }

    clear(queue, &errorCode);
    if (errorCode) {
        deleteQueue(queue, &errorCode);
        return errorCode;
    }

    enqueue(100, queue, &errorCode);
    if (errorCode) {
        deleteQueue(queue, &errorCode);
        return errorCode;
    }

    deleteQueue(queue, &errorCode);
    return 0;
}
