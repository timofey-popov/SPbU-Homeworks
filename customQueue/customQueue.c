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

// Создаёт пустую очередь.
// На вход принимает указатель на переменную с кодом ошибки.
// Возвращает указатель на очередь, если всё прошло нормально, в противном случае возвращает NULL и меняет код ошибки на 1.
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

// Добавляет элемент в конец очереди.
// На вход принимает добавляемое значение, указатель на очередь и указатель на переменную с кодом ошибки.
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

// Удаляет элемент из начала очереди и возвращает значение, которое в нём лежало.
// На вход принимает указатель на очередь и указатель на переменную с кодом ошибки.
Value dequeue(Queue* queue, ErrorCodes* errorCode) {
    if (queue == NULL) {
        *errorCode = dequeueGotNullPointer;
        return NULL;
    }

    if (queue->head == NULL) {
        *errorCode = dequeueQueueHasNoElemens;
        return NULL;
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

// Удаляет все элементы из очереди, никуда их не сохраняя.
// На вход принимает указатель на очередь и указатель на переменную с кодом ошибки.
void clear(Queue* queue, ErrorCodes* errorCode) {
    if (queue == NULL) {
        *errorCode = clearGotNullPointer;
        return;
    }

    while (queue->head != NULL) {
        dequeue(queue, errorCode);
    }
}

// Возвращает true, если очередь пуста, и false в противном случае.
// Если в качестве указателя на очередь передан NULL, возвращает false и меняет код ошибки на 7.
bool isEmpty(Queue* queue, ErrorCodes* errorCode) {
    if (queue == NULL) {
        *errorCode = isEmptyGotNullPointer;
        return NULL;
    }

    return queue->head == NULL;
}
// Удалить указанную очередь.
void deleteQueue(Queue* queue, ErrorCodes* errorCode) {
    if (queue == NULL) {
        *errorCode = deleteQueueGotNullPointer;
        return;
    }

    clear(queue, errorCode);
    free(queue);
}

