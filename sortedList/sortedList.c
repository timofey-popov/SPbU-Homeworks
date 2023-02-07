#include "sortedList.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

struct SortedList {
    ListElement* head;
    ListElement* tail;
};

SortedList* createList(ListErrors* errorCode) {
    SortedList* newList = calloc(1, sizeof(SortedList));
    if (newList == NULL) {
        *errorCode = memoryAllocationError;
        return NULL;
    }

    return newList;
}

void addToList(int value, SortedList* list, ListErrors* errorCode) {
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

    // Если список пуст:
    if (list->head == NULL) {
        list->head = newElement;
        list->tail = newElement;
        return;
    }

    // Если вставляем перед головой:
    if (list->head->value > value) {
        newElement->next = list->head;
        list->head = newElement;
        return;
    }

    // Если вставляем после хвоста:
    if (list->tail->value <= value) {
        list->tail->next = newElement;
        list->tail = newElement;
        return;
    }

    // Начинаем сразу со второго элемента, т. к. мы уже проверили, что первый элемент не больше нового.
    // Не выйдем за границу в цикле, т. к. проверили, что последний элемент точно больше нового.
    ListElement* preElement = list->head;
    ListElement* temporaryPointer = list->head->next;
    while (temporaryPointer->value <= value) {
        preElement = temporaryPointer;
        temporaryPointer = temporaryPointer->next;
    }

    preElement->next = newElement;
    newElement->next = temporaryPointer;
}

void deleteFromList(int value, SortedList* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    // Пустой список - значит, нечего удалять.
    if (list->head == NULL) {
        return;
    }

    // Начинаем поиск.
    ListElement* elementToDelete = list->head;
    ListElement* previousElement = NULL;
    while ((elementToDelete->value != value) && (elementToDelete != list->tail)) {
        previousElement = elementToDelete;
        elementToDelete = elementToDelete->next;
    }

    if (elementToDelete->value == value) {
        // Если "предыдущий" так и остался NULL, то мы хотим удалить первый (возможно, единственный) элемент.
        if (previousElement == NULL) {
            // Если он единственный - то зануляем ещё и хвост.
            if (list->head == list->tail) {
                list->tail = NULL;
            }

            ListElement* temporary = list->head;
            list->head = temporary->next;

            free(temporary);
            return;
        }

        // Если удаляем последний элемент - сдвигаем указатель хвоста.
        if (elementToDelete == list->tail) {
            list->tail = previousElement;
        }
        previousElement->next = elementToDelete->next;
        free(elementToDelete);
    }
}

void printWholeList(SortedList* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }
    
    if (list->head == NULL) {
        printf("No elements in the list.\n\n");
        return;
    }

    ListElement* temporaryPointer = list->head;

    printf("Here's the whole list:\n");
    while (temporaryPointer != NULL) {
        printf("%d ", temporaryPointer->value);
        temporaryPointer = temporaryPointer->next;
    }
    printf("\n\n");
}

void deleteList(SortedList* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    while (list->head != NULL) {
        deleteFromList(list->head->value, list, errorCode);
    }

    free(list);
}
