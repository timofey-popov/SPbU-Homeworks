#pragma once

// Коды ошибок:
typedef enum ListErrorCodes {
    noErrors,
} ListErrorCodes;

typedef int Value;

// АТД "Список"
typedef struct List List;

// Создать список.
// Возвращает указатель на созданный список или NULL, если создать не удалось.
// Если создать не удалось - память не выделятся, ничего удалять не нужно.
List* createList(ListErrorCodes* errorCode);

// Добавить элемент в список.
void addElement(Value value, List* list, ListErrorCodes* errorCode);

// Удалить элемент из списка.
void deleteElement(Value value, List* list, ListErrorCodes* errorCode);

// Распечатать весь список.
void printList(ListErrorCodes* errorCode);

// Удалить список.
void deleteList(ListErrorCodes* errorCode);
