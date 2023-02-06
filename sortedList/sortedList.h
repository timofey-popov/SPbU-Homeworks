#pragma once

// Коды ошибок.
typedef enum ListErrors {
    noErrors,
    memoryAllocationError,
    gotNullPointer
} ListErrors;

// АТД "Сортированный список".
typedef struct SortedList SortedList;

// Создать новый список. Если код ошибки не ноль - лист не был создан.
SortedList* createList(ListErrors* errorCode);

// Добавить значиение в список.
void addToList(int value, SortedList* list, ListErrors* errorCode);

// Удалить значение из списка.
// Будет удалено первое значение, совпадающее с заданным.
// Если такого значения нет - ничего не будет удалено, ошибки не возникнет.
void deleteFromList(int value, SortedList* list, ListErrors* errorCode);

// Распечатать весь список. Печатает сразу в консоль.
void printWholeList(SortedList* list, ListErrors* errorCode);

// Удалить сортированный список.
void deleteList(SortedList* list, ListErrors* errorCode);
