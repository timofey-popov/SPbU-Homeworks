#include "customQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Структура, являющаяся базовым элементом очереди.
// Хранит целое число и ссылку на следующий (ближе к концу очереди) элемент.
typedef struct QueueElement {
    Value value;
    struct QueueElement* next;
} QueueElement;

// Абстрактный тип данных "очередь".
// Хранит два указателя - на начало и на конец очереди.
typedef struct Queue {
    QueueElement* head;
    QueueElement* tail;
} Queue;

Queue* createQueue(ErrorCodes* errorCode) {
    Queue* newQueue = malloc(sizeof(Queue));

    if (newQueue == NULL) {
        *errorCode = createQueueMemoryError;
        return NULL;
    }

    newQueue->head = NULL;
    newQueue->tail = NULL;

    return newQueue;
}

void enqueue(Value value, Queue* queue, ErrorCodes* errorCode) {
    if (queue == NULL) {
        *errorCode = enqueueGotNullPointer;
        return;
    }

    QueueElement* newElement = malloc(sizeof(QueueElement));
    if (newElement == NULL) {
        *errorCode = enqueueMemoryError;
        return;
    }

    if (queue->head == NULL) {
        queue->head = newElement;
    } else {
        queue->tail->next = newElement;
    }

    newElement->value = value;
    newElement->next = NULL;

    queue->tail = newElement;
}

Value dequeue(Queue* queue, ErrorCodes* errorCode) {
    if (queue == NULL) {
        *errorCode = dequeueGotNullPointer;
        return -1;
    }

    if (queue->head == NULL) {
        *errorCode = dequeueQueueHasNoElemens;
        return -1;
    }

    Value valueToReturn = 0;

    if (queue->head == queue->tail) {
        valueToReturn = queue->head->value;
        free(queue->head);
        queue->head = NULL;
        queue->tail = NULL;

        return valueToReturn;
    }

    valueToReturn = queue->head->value;
    QueueElement* temporaryAddress = queue->head->next;
    free(queue->head);
    queue->head = temporaryAddress;

    return valueToReturn;
}

void clear(Queue* queue, ErrorCodes* errorCode) {
    if (queue == NULL) {
        *errorCode = clearGotNullPointer;
        return;
    }

    while (queue->head != NULL) {
        dequeue(queue, errorCode);
    }
}

bool isEmpty(Queue* queue, ErrorCodes* errorCode) {
    if (queue == NULL) {
        *errorCode = isEmptyGotNullPointer;
        return false;
    }

    return queue->head == NULL;
}

void deleteQueue(Queue* queue, ErrorCodes* errorCode) {
    if (queue == NULL) {
        *errorCode = deleteQueueGotNullPointer;
        return;
    }

    clear(queue, errorCode);
    free(queue);
}
