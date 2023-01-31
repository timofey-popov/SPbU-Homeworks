#include "customQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Функция для добавления элемента в конец очереди.
// На вход принимает значение для добавления, указатели на голову и хвост очереди и указатель на переменную с кодом ошибки.
void enqueue(int value, Unit** head, Unit** tail, int* errorCode) {
    Unit* newElement = malloc(sizeof(Unit));
    if (newElement == NULL) {
        *errorCode = 1;
        printf("Memory allocation problem.\n");
        return;
    }

    if (*head == NULL) {
        *head = newElement;
    } else {
        (*tail)->next = newElement;
    }

    newElement->value = value;
    newElement->next = NULL;

    *tail = newElement;

    printf("%d enqueued.\n", value);
}

// Функция для удаелния элемента из начала очереди.
// На вход принимает указатели на хвост, голову очереди и на переменную с кодом ошибки.
// Возвращает значение, которое было в удалённом элементе очереди.
int dequeue(Unit** head, Unit** tail, int* errorCode) {
    if (*head == NULL) {
        *errorCode = 1;
        printf("Zero element dequeue attempt.\n");
        return -1;
    }

    int valueToReturn = 0;

    if (*head == *tail) {
        valueToReturn = (*head)->value;
        free(*head);
        *head = NULL;
        *tail = NULL;

        printf("Element dequeued successfully. This element was %d.\n", valueToReturn);
        return valueToReturn;
    }

    valueToReturn = (*head)->value;
    Unit* tempAddress = (*head)->next;
    free(*head);
    *head = tempAddress;

    printf("Element dequeued successfully. This element was %d.\n", valueToReturn);
    return valueToReturn;
}

// Функция для очистки очереди.
// На вход принимает указатели на хвост, голову очереди и на переменную с кодом ошибки.
void clear(Unit** head, Unit** tail, int* errorCode) {
    while (*head != NULL && *tail != NULL) {
        dequeue(head, tail, errorCode);
    }

    printf("Queue is empty now.\n");
}

// Функция-проверка очереди на пустоту.
// Возвращает true, если очередь пуста, и false в обратном случае.
bool isEmpty(Unit** head) {
    return *head == NULL;
}

int main(void) {
    int errorCode = 0;
    Unit* head = NULL;
    Unit* tail = NULL;

    enqueue(5, &head, &tail, &errorCode);
    if (errorCode) {
        return -1;
    }

    dequeue(&head, &tail, &errorCode);
    if (errorCode) {
        return -1;
    }

    enqueue(100, &head, &tail, &errorCode);
    if (errorCode) {
        return -1;
    }

    clear(&head, &tail, &errorCode);

    enqueue(100, &head, &tail, &errorCode);
    if (errorCode) {
        return -1;
    }

    return 0;
}