#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tests.h"

// Структура для элементов двусвязного списка.
typedef struct ListElement {
    int value;
    struct ListElement* next;
    struct ListElement* prev;
} ListElement;

// АТД "двусвязный список".
typedef struct DoublyLinkedList {
    ListElement* head;
    ListElement* tail;
} DoublyLinkedList;

// Создать двусвязный список.
// На вход принимает указатель на код ошибки, возвращает указатель на созданный список.
DoublyLinkedList* createDoublyLinkedList(int* errorCode) {
    DoublyLinkedList* newList = malloc(sizeof(DoublyLinkedList));
    if (newList == NULL) {
        *errorCode = 1;
        return NULL;
    }

    newList->head = NULL;
    newList->tail = NULL;

    return newList;
}

// Добавить элемент в конец списка.
// Возвращает 0, если всё прошло успешно и 1 в противном случае.
void pushToTail(int value, DoublyLinkedList* list, int* errorCode) {
    ListElement* newElement = malloc(sizeof(ListElement));
    if (newElement == NULL) {
        *errorCode = 2;
        return;
    }

    if (list->head == NULL) {
        list->head = newElement;
        list->tail = newElement;
        newElement->prev = NULL;
    } else {
        list->tail->next = newElement;
        newElement->prev = list->tail;
    }

    newElement->value = value;
    newElement->next = NULL;

    list->tail = newElement;
    return 0;
}

// Функция, полностью очищающая список.
void clear(DoublyLinkedList* list, int* errorCode) {
    if (list->tail == NULL) {
        *errorCode = 3;
        return;
    }

    while (true) {
        ListElement* temporary = list->tail;
        list->tail = list->tail->prev;
        free(temporary);
        if (list->tail == NULL) {
            return;
        }
    }
}

// Функция, заполняющая список с начала значениями из файла с помощью функции push.
void fill(FILE* file, DoublyLinkedList* list, int* errorCode) {
    if (list == NULL) {
        *errorCode = 4;
        return;
    }

    int value = 0;
    int correctnessCheck = fscanf(file, "%d", &value);

    while (correctnessCheck != EOF) {
        pushToTail(value, list, errorCode);
        correctnessCheck = fscanf(file, "%d", &value);
    }
    
    return;
}

// Функция проверки списка на симметричность.
bool isSymmetrical(DoublyLinkedList* list, int* errorCode) {
    if (list->tail == NULL) {
        *errorCode = 5;
        return false;
    }

    if (list->head == list->tail) {
        return true;
    }

    ListElement* left = list->head;
    ListElement* right = list->tail;

    while (left != right) {
        if (left->value != right->value) {
            return false;
        }

        left = left->next;
        right = right->prev;
    }

    return true;
}

// Функция удаления списка.
void deleteList(DoublyLinkedList* list, int* errorCode) {
    if (list == NULL) {
        *errorCode = 6;
        return false;
    }

    if (list->tail != NULL) {
        clear(list, errorCode);
    }

    free(list);
}
