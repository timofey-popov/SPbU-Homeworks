#pragma once

#include <stdbool.h>

// Коды ошибок.
typedef enum ListErrors {
    noErrors,
    memoryAllocationError,
    gotNullPointer
} ListErrors;

// АТД "Циклический список".
typedef struct CircularList CircularList;

// Создать новый список. Если код ошибки не ноль - список не был создан.
CircularList* createList(ListErrors* errorCode);

// Добавить значиение в список.
void addToList(int value, CircularList* list, ListErrors* errorCode);

// Удалить значение из списка.
// Будет удалено первое значение, совпадающее с заданным.
// Если такого значения нет - ничего не будет удалено, ошибки не возникнет.
void deleteFromList(int value, CircularList* list, ListErrors* errorCode);

// Возвращает номер k позиции последнего живого воина, если воинов n и убивают каждого m-того.
int calculateSuitablePosition(int n, int m, CircularList* list, ListErrors* errorCode);

// Удалить список.
void deleteList(CircularList* list, ListErrors* errorCode);