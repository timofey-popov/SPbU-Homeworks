#include <stdlib.h>

#include "customQueue.h"

int main(void) {
    ErrorCodes errorCode = noErrors;

    Queue* queue = createQueue(&errorCode);
    if (errorCode) {
        return errorCode;
    }

    enqueue(5, queue, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    dequeue(queue, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    enqueue(100, queue, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    clear(queue, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    enqueue(100, queue, &errorCode);
    if (errorCode) {
        return errorCode;
    }

    deleteQueue(queue, &errorCode);

    return 0;
}
