#pragma once

#include <stdbool.h>

// Коды ошибок.
typedef enum ErrorCodes {
    noErrors,
    memoryAllocationError,
    gotNullPointer,
    treeIsEmpty
} ErrorCodes;

// АТД "Словарь".
// Позволяет организовать хранение данных и поиск значений по ключу.
typedef struct Dictionary Dictionary;

// Тип данных для хранимых в словаре значений.
typedef int Value;

// Создать словарь. Возвращает указатель на созданный словарь или NULL, если произошла ошибка.
Dictionary* createDictionary(ErrorCodes* errorCode);

// Добавить значение в словарь с заданным ключом.
// На вход принимает значение, ключ, словарь и переменную с кодом ошибки.
// Если такой ключ уже был в словаре, значение заменяется на новое.
void addValue(Value value, int key, Dictionary* dictionary, ErrorCodes* errorCode);

// Получить значение по ключу. На вход принимает ключ, словарь и переменную с кодом ошибки.
// Если такого ключа в словаре нет, возвращает NULL и не изменяет код ошибки.
Value getValueByKey(int key, Dictionary* dictionary, ErrorCodes* errorCode);

// Вернёт true, если такой ключ есть в словаре, и false в обратном случае.
bool isSuchKey(int key, Dictionary* dictionary, ErrorCodes* errorCode);

// Удалить ключ и связанное с ним значение из словаря.
// Если такого ключа в словаре нет, ничего не произойдёт и код ошибки не поменяется.
void deleteKeyAndItsValue(int key, Dictionary* dictionary, ErrorCodes* errorCode);

// Удалить словарь. Возвращает true, если всё прошло успешно, и false в противном случае.
void deleteDictionary(Dictionary* dictionaryToRemove, ErrorCodes* errorCode);
