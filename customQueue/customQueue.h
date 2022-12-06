#pragma once

#include <stdbool.h>

// Коды ошибок:
// 0 - нет ошибок.
// 1 - ошибка выделения памяти под новую очередь (createQueue).
// 2 - в качестве указателя на очередь передан NULL (enqueue).
// 3 - ошибка выделения памяти под новый элемент очереди (enqueue).
// 4 - в качестве указателя на очередь передан NULL (dequeue).
// 5 - в очереди нет элеменетов для dequeue (dequeue).
// 6 - в качестве указателя на очередь передан NULL (clear).
// 7 - в качестве указателя на очередь передан NULL (isEmpty).
// 8 - в качестве указателя на очередь передан NULL (deleteQueue).
typedef enum ErrorCodes {
    noErrors,
    createQueueMemoryError,
    enqueueGotNullPointer,
    enqueueMemoryError,
    dequeueGotNullPointer,
    dequeueQueueHasNoElemens,
    clearGotNullPointer,
    isEmptyGotNullPointer,
    deleteQueueGotNullPointer
} ErrorCodes;

// Тип данных для хранения в очереди.
// Если нужно поменять - меняем тип данных в этом месте.
typedef int Value;

// Абстрактный тип данных "очередь".
typedef struct Queue Queue;

// Создаёт пустую очередь.
// На вход принимает указатель на переменную с кодом ошибки.
// Возвращает указатель на очередь, если всё прошло нормально, в противном случае возвращает NULL и меняет код ошибки.
Queue* createQueue(ErrorCodes* errorCode);

// Добавляет элемент в конец очереди.
// На вход принимает добавляемое значение, указатель на очередь и указатель на переменную с кодом ошибки.
void enqueue(Value value, Queue* queue, ErrorCodes* errorCode);

// Удаляет элемент из начала очереди и возвращает значение, которое в нём лежало.
// На вход принимает указатель на очередь и указатель на переменную с кодом ошибки.
Value dequeue(Queue* queue, ErrorCodes* errorCode);

// Удаляет все элементы из очереди, никуда их не сохраняя.
// На вход принимает указатель на очередь и указатель на переменную с кодом ошибки.
void clear(Queue* queue, ErrorCodes* errorCode);

// Возвращает true, если очередь пуста, и false в противном случае.
// Если в качестве указателя на очередь передан NULL, возвращает false и меняет код ошибки.
bool isEmpty(Queue* queue, ErrorCodes* errorCode);

// Удалить указанную очередь.
void deleteQueue(Queue* queue, ErrorCodes* errorCode);
