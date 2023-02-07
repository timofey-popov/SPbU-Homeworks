#include "circularList.h"

#include <stdlib.h>

typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

struct CircularList {
    ListElement* head;
    ListElement* tail;
};

CircularList* createList(ListErrors* errorCode) {
    CircularList* newList = calloc(1, sizeof(CircularList));
    if (newList == NULL) {
        *errorCode = memoryAllocationError;
        return NULL;
    }

    return newList;
}

void addToList(int value, CircularList* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    // Создание нового элемента списка.
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL) {
        *errorCode = memoryAllocationError;
        return;
    }
    newElement->value = value;

    // Если добавляем в пустой список:
    if (list->head == NULL) {
        list->head = newElement;
        list->tail = newElement;
        newElement->next = newElement;
        return;
    }

    // В остальных случаях:
    list->tail->next = newElement;
    list->tail = newElement;
    newElement->next = list->head;
}

void deleteFromList(int value, CircularList* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    // Пустой список - значит, нечего удалять.
    if (list->head == NULL) {
        return;
    }

    // Начинаем поиск.
    ListElement* previousElement = list->tail;
    ListElement* temporaryPointer = list->head;

    while ((temporaryPointer->value != value) && (temporaryPointer != list->tail)) {
        previousElement = temporaryPointer;
        temporaryPointer = temporaryPointer->next;
    }

    // Если нашли совпадение:
    if (temporaryPointer->value == value) {
        previousElement->next = temporaryPointer->next;
        // Если удаляем голову:
        if (temporaryPointer == list->head) {
            list->head = list->head->next;
        }

        // Если удаляем хвост:
        if (temporaryPointer == list->tail) {
            list->tail = previousElement;
        }

        // Если в списке всего один элемент:
        if (temporaryPointer == previousElement) {
            list->head = NULL;
            list->tail = NULL;
        }

        free(temporaryPointer);
    }
}

int calculateSuitablePosition(int n, int m, CircularList* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return -1;
    }

    ListElement* pointer = list->tail;
    ListElement* nextMove = list->head;

    // Остановимся, когда в списке останется только один элемент.
    while (list->head != list->tail) {
        pointer = nextMove;

        // Делаем m - 1 шаг, т. к. один шаг уже сделали, когда перешли на nextMove.
        for (int i = 0; i < m - 1; ++i) {
            pointer = pointer->next;
        }

        // Запоминаем следующий шаг и удаляем ту позицию, куда показывает указатель:
        nextMove = pointer->next;
        deleteFromList(pointer->value, list, errorCode);
        if (*errorCode) {
            return -1;
        }
    }

    return nextMove->value;
}

void deleteList(CircularList* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    while (list->head != NULL) {
        deleteFromList(list->head->value, list, errorCode);
    }

    free(list);
}