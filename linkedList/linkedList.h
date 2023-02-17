#pragma once

#include <stdbool.h>

// Коды ошибок:
typedef enum ListErrors {
    noErrors,
    memoryAllocationError,
    gotNullPointer, 
    gotInvalidNumber,
    noSuchElementInList
} ListErrors;

// Тип данных, хранимых в списке.
typedef int Value;

// АТД "Список".
typedef struct List List;

// Создать список.
// Возвращает указатель на созданный список или NULL, если создать не удалось.
// Если создать не удалось - память не выделятся, ничего удалять не нужно.
List* createList(ListErrors* errorCode);

// Добавить элемент в список.
void addElement(Value value, List* list, ListErrors* errorCode);

// Удалить элемент из списка (поиск по значению).
void deleteElementByValue(Value value, List* list, ListErrors* errorCode);

// Получить количество элементов в списке.
int getListLength(List* list, ListErrors* errorCode);

// Получить n-тое значение списка (нумерация от 1), не удаляя его.
Value getNthValue(List* list, int number, ListErrors* errorCode);

// Получить n-тое значение списка (нумерация от 1) и удалить n-тый элемент.
Value popNthElement(List* list, int number, ListErrors* errorCode);

// Возвращает true, если список пуст, и false в противном случае.
bool isEmpty(List* list, ListErrors* errorCode);

// Распечатать весь список.
void printList(List* list, ListErrors* errorCode);

// Удалить список.
void deleteList(List* list, ListErrors* errorCode);
