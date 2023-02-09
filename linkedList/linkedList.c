#include "linkedList.h"

#include <stdlib.h>
#include <stdio.h>

// Структура для элементов списка.
// Поля: значение и указатель на следующий элемент.
typedef struct ListElement {
    Value value;
    struct ListElement* next;
} ListElement;

typedef struct List {
    ListElement* head;
    ListElement* tail;
    int length;
} List;

List* createList(ListErrors* errorCode) {
    List* newList = calloc(1, sizeof(List));
    if (newList == NULL) {
        *errorCode = memoryAllocationError;
        return NULL;
    }

    return newList;
}

void addElement(Value value, List* list, ListErrors* errorCode) {
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
        list->length += 1;
        return;
    }

    list->tail->next = newElement;
    list->tail = newElement;
    list->length += 1;
}

void deleteElementByValue(Value value, List* list, ListErrors* errorCode) {
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

    // Если нашли то, что искали, запускаем удаление по указателю на предыдущий элемент:
    if (elementToDelete->value == value) {
        deleteElementByPointer(list, previousElement, errorCode);
    }
}

// Удаляет элемент, следующий за тем, на который передан указатель.
void deleteElementByPointer(List* list, ListElement* previousElement, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    // Пустой список - значит, нечего удалять.
    if (list->head == NULL) {
        return;
    }

    ListElement* elementToDelete = NULL;

    // Если "предыдущий" элемент NULL, то предполагаем, что мы хотим удалить первый (возможно, единственный) элемент.
    if (previousElement == NULL) {
        elementToDelete = list->head;
    }
    else {
        elementToDelete = previousElement->next;
    }

    // Если этот элемент ноль - вероятно, нам передали хвост списка или просто некорректное значение.
    if (elementToDelete == NULL) {
        *errorCode = noSuchElementInList;
        return;
    }

    if (previousElement == NULL) {
        // Если он единственный - то зануляем ещё и хвост.
        if (list->head == list->tail) {
            list->tail = NULL;
        }

        ListElement* temporary = list->head;
        list->head = temporary->next;

        free(temporary);
        list->length -= 1;
        return;
    }

    // Если удаляем последний элемент - сдвигаем указатель хвоста.
    if (elementToDelete == list->tail) {
        list->tail = previousElement;
    }
    previousElement->next = elementToDelete->next;
    free(elementToDelete);
    list->length -= 1;
}

int getListLength(List* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    return list->length;
}

Value getNthValue(List* list, int number, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return -1;
    }

    if (number < 1 || number > list->length) {
        *errorCode = gotInvalidNumber;
        return -1;
    }

    ListElement* pointer = list->head;
    for (int i = 1; i < number; ++i) {
        pointer = pointer->next;
    }

    return pointer->value;
}

Value popNthElement(List* list, int number, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return -1;
    }

    if (number < 1 || number > list->length) {
        *errorCode = gotInvalidNumber;
        return -1;
    }

    ListElement* pointer = list->head;
    // Двигаемся n - 2 раза, т. к. начинаем с первого элемента, и нужен нам указатель не на удаляемый элемент, а на предшествующий ему.
    for (int i = 0; i < number - 2; ++i) {
        pointer = pointer->next;
    }

    Value valueToReturn = pointer->next->value;

    deleteElementByPointer(list, pointer, errorCode);

    return valueToReturn;
}

void printList(List* list, ListErrors* errorCode) {
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

void deleteList(List* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    while (list->head != NULL) {
        deleteElementByValue(list->head->value, list, errorCode);
    }

    free(list);
}