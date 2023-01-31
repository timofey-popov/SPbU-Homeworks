#include "task2.h"

#include <stdlib.h>
#include <string.h>

typedef struct ListElement {
    char* stringValue;
    struct ListElement* next;
} ListElement;

struct List {
    ListElement* head;
};

List* createList(ErrorCodes* errorCode) {
    List* newList = calloc(1, sizeof(List));
    if (newList == NULL) {
        *errorCode = memoryError;
        return NULL;
    }

    return newList;
}

void addElement(List* list, char* value, ErrorCodes* errorCode) {
    if (list == NULL || value == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL) {
        *errorCode = memoryError;
        return;
    }

    newElement->stringValue = value;

    if (list->head == NULL) {
        list->head = newElement;
        return;
    }

    list->head->next = newElement;
    list->head = newElement;
}

void deleteList(List* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    ListElement* pointer = list->head;

    while (pointer) {
        ListElement* temporary = pointer->next;
        free(pointer);
        pointer = temporary;
    }

    free(list);
}

void addAStrings(List* list, ErrorCodes* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    // Список пуст - ничего не делаем.
    if (list->head == NULL) {
        return;
    }

    ListElement* tail = list->head;

    // Раз список не пуст, хотя бы один элемент в нём есть.
    int counterOfCurrentRecords = 1;

    // Считаем количество элементов в списке, заодно находим его хвост.
    while (tail->next) {
        tail = tail->next;
        counterOfCurrentRecords += 1;
    }

    // Снова идём по списку с начала и до последнего (не только что добавленного) элемента, ищем строки на 'a'
    // Если находим - создаём новый элемент, копируем в него эту строку, вешаем на него указатель из предыдущего хвоста, а его делаем текущим хвостом.
    // После этого добавлять будем уже после него.
    ListElement* pointer = list->head;
    for (int i = 0; i < counterOfCurrentRecords - 1; ++i) {
        if (pointer->stringValue[0] == 'a') {
            ListElement* newElement = calloc(1, sizeof(ListElement));
            if (newElement == NULL) {
                *errorCode = memoryError;
                return;
            }

            strcpy(newElement->stringValue, pointer->stringValue);
            tail->next = newElement;
            tail = newElement;
        }

        // Двигаемся к следующему элементу.
        pointer = pointer->next;
    }
}