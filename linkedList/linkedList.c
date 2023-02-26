#include "linkedList.h"

#include <stdlib.h>
#include <stdio.h>

// Структура для элементов списка.
// Поля: значение, указатель на следующий элемент.
typedef struct ListElement {
    Value value;
    struct ListElement* next;
} ListElement;

// Список. Поля: указатели на голову и хвост, длина списка.
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

// Удаляет элемент, следующий за тем, на который передан указатель.
// Если передан NULL, удаляет голову.
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

int getListLength(List* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return -1;
    }

    return list->length;
}

// Возвращает указатель на (n - 1)-ый элемент списка.
// Служебная функция, не проверяет корректность указателя на список и существует ли такой номер.
// Если это голова списка - возвращает NULL. Если список пуст - тоже возвращает NULL и меняет код ошибки.
ListElement* getPreviousToNthElement(List* list, int number, ListErrors* errorCode) {
    if (list->length == 0) {
        *errorCode = gotEmptyList;
        return NULL;
    }

    if (number == 1) {
        return NULL;
    }

    ListElement* pointer = list->head;
    for (int i = 1; i < number - 1; ++i) {
        pointer = pointer->next;
    }

    return pointer;
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

    ListElement* previous = getPreviousToNthElement(list, number, errorCode);
    if (*errorCode) {
        return -1;
    }

    return previous == NULL ? list->head->value : previous->next->value;
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

    ListElement* previous = getPreviousToNthElement(list, number, errorCode);
    if (*errorCode) {
        return -1;
    }

    Value valueToReturn = previous == NULL ? list->head->value : previous->next->value;

    deleteElementByPointer(list, previous, errorCode);

    return valueToReturn;
}

bool isEmpty(List* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return true;
    }

    return list->head == NULL;
}

void clearList(List* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    // Передаём показатель на "предыдущий" к голове элемент, то есть на NULL.
    while (list->head != NULL) {
        deleteElementByPointer(list, NULL, errorCode);
    }
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

    clearList(list, errorCode);
    free(list);
}