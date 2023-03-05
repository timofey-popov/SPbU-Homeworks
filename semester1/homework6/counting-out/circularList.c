#include "circularList.h"

#include <stdlib.h>

// Элемент циклического списка.
// "Next" для последнего элемента - это голова списка.
typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

// "Циклический список".
// Представляет из себя указатели на голову и хвост списка. 
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

// Удалить элемент, следующий за переданным в функцию указателем.
void deleteElementByPointer(CircularList* list, ListElement* previousElement, ListErrors* errorCode) {
    if (list == NULL || previousElement == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    ListElement* elementToDelete = previousElement->next;

    previousElement->next = elementToDelete->next;

    // Если удаляем голову:
    if (elementToDelete == list->head) {
        list->head = list->head->next;
    }

    // Если удаляем хвост:
    if (elementToDelete == list->tail) {
        list->tail = previousElement;
    }

    // Если в списке всего один элемент:
    if (elementToDelete == previousElement) {
        list->head = NULL;
        list->tail = NULL;
    }

    free(elementToDelete);
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
        deleteElementByPointer(list, previousElement, errorCode);
    }
}

// Удалить список.
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

int calculateSuitablePosition(int n, int m, ListErrors* errorCode) {
    CircularList* list = createList(errorCode);
    if (*errorCode || (list == NULL)) {
        return -1;
    }

    // Набиваем в список n номеров воинов по порядку:
    for (int i = 1; i <= n; ++i) {
        addToList(i, list, errorCode);
        if (*errorCode) {
            deleteList(list, errorCode);
            return -1;
        }
    }

    ListElement* pointer = list->tail;

    // Остановимся, когда в списке останется только один элемент.
    while (list->head != list->tail) {
        // Всегда делаем m - 1 шаг, т. к один из элементов впереди удаляется, его считать не надо.
        for (int i = 0; i < m - 1; ++i) {
            pointer = pointer->next;
        }

        // Удаляем следующую позицию после той, на которую показывает указатель.
        deleteElementByPointer(list, pointer, errorCode);
        if (*errorCode) {
            deleteList(list, errorCode);
            return -1;
        }
    }
    int valueToReturn = pointer->value;

    deleteList(list, errorCode);
    return valueToReturn;
}