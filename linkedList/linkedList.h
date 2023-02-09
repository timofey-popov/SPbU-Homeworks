#pragma once

// Коды ошибок:
typedef enum ListErrors {
    noErrors,
    memoryAllocationError,
    gotNullPointer
} ListErrors;

typedef int Value;

// АТД "Список"
typedef struct List List;

// Создать список.
// Возвращает указатель на созданный список или NULL, если создать не удалось.
// Если создать не удалось - память не выделятся, ничего удалять не нужно.
List* createList(ListErrors* errorCode);

// Добавить элемент в список.
void addElement(Value value, List* list, ListErrors* errorCode);

// Удалить элемент из списка (поиск по значению).
void deleteElementByValue(Value value, List* list, ListErrors* errorCode);

// Распечатать весь список.
void printList(List* list, ListErrors* errorCode);

// Удалить список.
void deleteList(List* list, ListErrors* errorCode);
