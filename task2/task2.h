#pragma once

#include <stdbool.h>

// Коды ошибок.
typedef enum ErrorCodesForSet {
    noErrors,
    memoryAllocationError,
    gotNullPointer
} ErrorCodesForSet;

// Тип данных для элементов множеств.
typedef int Value;

// АТД множество.
typedef struct Set Set;

// Создать новое множество из одного элемента.
// Выделяет память, нужно быть внимательным и не забывать удалить (freeSet);
Set* createSet(Value value, ErrorCodesForSet* errorCode);

// Объединить два множества в одно.
// Не выделяет никакую память. В случае ошибки удалять нужно только исходные множества.
Set* unite(Set* set1, Set* set2, ErrorCodesForSet* errorCode);

// Являются ли множества элементами одного множества.
bool isTheSameSet(Set* set1, Set* set2, ErrorCodesForSet* errorCode);

// Удалить всё множество, в котором "лежит" это подмножество.
void freeSet(Set* set, ErrorCodesForSet* errorCode);