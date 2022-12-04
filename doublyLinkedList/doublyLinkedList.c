#include "doublyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    LinkedList* newList = malloc(sizeof(LinkedList));
    if (newList == NULL) {
        *errorCode = createListMemoryError;
        return NULL;
    }

    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;

    return newList;
}

void pushToHead(Value value, LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = pushToHeadGotNullPointer;
        return;
    }

    ListElement* newElement = malloc(sizeof(ListElement));
    if (newElement == NULL) {
        *errorCode = pushToHeadMemoryError;
        return;
    }

    newElement->value = value;
    newElement->prev = NULL;
    newElement->next = list->head;

    list->head = newElement;

    if (list->size == 0) {
        list->tail = newElement;
    }

    list->size += 1;
}

void pushToTail(Value value, LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = pushToTailGotNullPointer;
        return;
    }

    ListElement* newElement = malloc(sizeof(ListElement));
    if (newElement == NULL) {
        *errorCode = pushToTailMemoryError;
        return;
    }

    newElement->value = value;
    newElement->prev = list->tail;
    newElement->next = NULL;

    list->tail = newElement;

    if (list->size == 0) {
        list->head = newElement;
    }

    list->size += 1;
}

// Вспомогательная функция.
// Возвращает указатель на n-тый элемент списка.
ListElement* getNthElement(LinkedList* list, int n) {
    if (n <= list->size / 2) {
        ListElement* elementToReturn = list->head;

        for (int i = 1; i < n; ++i) {
            elementToReturn = elementToReturn->next;
        }

        return elementToReturn;
    }

    ListElement* elementToReturn = list->tail;

    for (int i = 0; i < list->size - n; ++i) {
        elementToReturn = elementToReturn->prev;
    }

    return elementToReturn;
}

void insertNthElement(Value value, int n, LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = insertNthElementGotNullPointer;
        return;
    }

    if (n > list->size) {
        *errorCode = noSuchNumberInList;
        return;
    }

    ListElement* currentNthElement = getNthElement(list, n);

    ListElement* newElement = malloc(sizeof(ListElement));
    if (newElement == NULL) {
        *errorCode = insertNthElementMemoryError;
        return;
    }

    newElement->value = value;
    newElement->prev = currentNthElement->prev;
    newElement->next = currentNthElement;

    currentNthElement->prev->next = newElement;
    currentNthElement->prev = newElement;

    list->size += 1;
}

Value popFromHead(LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = popFromHeadGotNullPointer;
        return NULL;
    }

    if (list->size == 0) {
        *errorCode = popFromHeadGotEmptyList;
        return NULL;
    }

    Value valueToReturn = list->head->value;
    ListElement* temporary = list->head->next;
    free(list->head);
    list->head = temporary;

    return valueToReturn;
}

Value popFromTail(LinkedList* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = popFromTailGotNullPointer;
        return;
    }

    if (list->size == 0) {
        *errorCode = popFromTailGotEmptyList;
        return NULL;
    }

    Value valueToReturn = list->tail->value;
    ListElement* temporary = list->tail->prev;
    free(list->tail);
    list->tail = temporary;

    return valueToReturn;
}

Value popNthElement(LinkedList* list, int n, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = popNthElementGotNullPointer;
        return NULL;
    }

    if (list->size == 0) {
        *errorCode = popNthElementGotEmptyList;
        return NULL;
    }

    ListElement* currentNthElement = getNthElement(list, n);

    Value valueToReturn = currentNthElement->value;

    currentNthElement->prev->next = currentNthElement->next;
    currentNthElement->next->prev = currentNthElement->prev;

    free(currentNthElement);
    return valueToReturn;
}

Value getNthValue(LinkedList* list, int n, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = getNthValueGotNullPointer;
        return;
    }

    if (list->size == 0) {
        *errorCode = getNthValueGotEmptyList;
        return NULL;
    }

    return getNthElement(list, n)->value;
}

int main(void) {



    return 0;
}