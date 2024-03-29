﻿#include "doublyLinkedList.h"

#include <stdlib.h>

// Структура для элементов списка.
// Поля: значение, указатели на предыдущий и следующий элементы.
typedef struct ListElement {
    Value value;
    struct ListElement* prev;
    struct ListElement* next;
} ListElement;

// АТД структура "двусвязный список".
// Элемент списка - структура ListElement.
// Поля: указатель на начало списка, указатель на конец списка, количество элементов в списке.
typedef struct LinkedList {
    ListElement* head;
    ListElement* tail;
    int size;
} LinkedList;

LinkedList* createLinkedList(ErrorCodes* errorCode) {
    LinkedList* newList = calloc(1, sizeof(LinkedList));
    if (newList == NULL) {
        *errorCode = memoryAllocationError;
        return NULL;
    }

    return newList;
}

void pushToHead(Value value, LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = nullPointerReceived;
        return;
    }

    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL) {
        *errorCode = memoryAllocationError;
        return;
    }

    newElement->value = value;
    newElement->prev = NULL;
    newElement->next = list->head;

    if (list->head != NULL) {
        list->head->prev = newElement;
    }
    else {
        list->tail = newElement;
    }

    list->head = newElement;

    list->size += 1;
}

void pushToTail(Value value, LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = nullPointerReceived;
        return;
    }

    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL) {
        *errorCode = memoryAllocationError;
        return;
    }

    newElement->value = value;
    newElement->prev = list->tail;
    newElement->next = NULL;

    if (list->tail != NULL) {
        list->tail->next = newElement;
    }
    else {
        list->head = newElement;
    }

    list->tail = newElement;

    list->size += 1;
}

// Вспомогательная функция.
// Возвращает указатель на n-тый элемент списка.
// Не проверяет, что указатель на список ненулевой, это должна сделать вызывающая функция.
ListElement* getNthElement(LinkedList* list, int n) {
    if (n <= list->size / 2) {
        ListElement* elementToReturn = list->head;

        for (int i = 1; i < n; ++i) {
            elementToReturn = elementToReturn->next;
        }

        return elementToReturn;
    }

    ListElement* elementToReturn = list->tail;

    for (int i = 0; i < (list->size - n); ++i) {
        elementToReturn = elementToReturn->prev;
    }

    return elementToReturn;
}

void insertNthElement(Value value, int n, LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = nullPointerReceived;
        return;
    }

    if (list->size == 0 || n > list->size || n < 1) {
        *errorCode = noSuchNumberInList;
        return;
    }

    ListElement* currentNthElement = getNthElement(list, n);

    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL) {
        *errorCode = memoryAllocationError;
        return;
    }

    newElement->value = value;
    newElement->prev = currentNthElement->prev;
    newElement->next = currentNthElement;

    if (n != 1) {
        currentNthElement->prev->next = newElement;
    }
    else {
        list->head = newElement;
    }

    currentNthElement->prev = newElement;

    list->size += 1;
}

Value popFromHead(LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = nullPointerReceived;
        return -1;
    }

    if (list->size == 0) {
        *errorCode = emptyListReceived;
        return -1;
    }

    Value valueToReturn = list->head->value;
    ListElement* temporary = list->head->next;

    free(list->head);
    list->head = temporary;

    if (list->size == 1) {
        list->tail = NULL;
    }
    else {
        list->head->prev = NULL;
    }

    list->size -= 1;

    return valueToReturn;
}

Value popFromTail(LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = nullPointerReceived;
        return -1;
    }

    if (list->size == 0) {
        *errorCode = emptyListReceived;
        return -1;
    }

    Value valueToReturn = list->tail->value;
    ListElement* temporary = list->tail->prev;

    free(list->tail);
    list->tail = temporary;

    if (list->size == 1) {
        list->head = NULL;
    }
    else {
        list->tail->next = NULL;
    }

    list->size -= 1;

    return valueToReturn;
}

Value popNthElement(LinkedList* list, int n, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = nullPointerReceived;
        return -1;
    }

    if (list->size == 0 || n > list->size || n < 1) {
        *errorCode = noSuchNumberInList;
        return -1;
    }

    ListElement* currentNthElement = getNthElement(list, n);

    Value valueToReturn = currentNthElement->value;

    if (n == 1) {
        list->head = currentNthElement->next;
    }
    else {
        currentNthElement->prev->next = currentNthElement->next;
    }

    if (n == list->size) {
        list->tail = currentNthElement->prev;
    }
    else {
        currentNthElement->next->prev = currentNthElement->prev;
    }

    free(currentNthElement);

    list->size -= 1;

    return valueToReturn;
}

Value getNthValue(LinkedList* list, int n, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = nullPointerReceived;
        return -1;
    }

    if (list->size == 0 || n > list->size || n < 1) {
        *errorCode = noSuchNumberInList;
        return -1;
    }

    return getNthElement(list, n)->value;
}

bool isEmpty(LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = nullPointerReceived;
        return false;
    }

    return list->head == NULL;
}

void clearList(LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = nullPointerReceived;
        return;
    }

    while (list->size) {
        popFromTail(list, errorCode);
    }
}

void deleteLinkedList(LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = nullPointerReceived;
        return;
    }

    clearList(list, errorCode);
    free(list);
}
