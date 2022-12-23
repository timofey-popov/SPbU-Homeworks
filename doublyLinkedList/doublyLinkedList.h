#pragma once

#include <stdbool.h>

// Коды ошибок:
// 0 - нет ошибок.
// 1 - ошибка выделения памяти.
// 2 - в качестве указателя на список передан NULL.
// 3 - в списке нет элемента с таким номером.
// 4 - в списке нет элементов.
typedef enum ErrorCodes {
    noErrors,
    memoryAllocationError,
    nullPointerReceived,
    noSuchNumberInList,
    emptyListReceived
} ErrorCodes;

// Тип данных, хранящихся в списке. Если нужно его поменять - меняй здесь.
typedef int Value;

// АТД структура "двусвязный список".
typedef struct LinkedList LinkedList;

// Создать список.
// Возвращает указатель на созданный список или NULL, если произошла ошибка.
// В случае ошибки список не создаётся, удалять его не нужно.
LinkedList* createLinkedList(ErrorCodes* errorCode);

// Добавить элемент в начало списка.
void pushToHead(Value value, LinkedList* list, ErrorCodes* errorCode);

// Добавить элемент в конец списка.
void pushToTail(Value value, LinkedList* list, ErrorCodes* errorCode);

// Вставить элемент на n-тое место в списке (нумерация от 1).
void insertNthElement(Value value, int n, LinkedList* list, ErrorCodes* errorCode);

// Получить значение первого элемента в списке и удалить этот элемент.
// Возвращает значение, которое лежало в этом элементе.
Value popFromHead(LinkedList* list, ErrorCodes* errorCode);

// Получить значение последнего элемента в списке и удалить этот элемент.
// Возвращает значение, которое лежало в этом элементе.
Value popFromTail(LinkedList* list, ErrorCodes* errorCode);

// Получить значение n-того элемента в списке (нумерация от 1) и удалить этот элемент.
// Возвращает значение, которое лежало в этом элементе.
Value popNthElement(LinkedList* list, int n, ErrorCodes* errorCode);

// Получить значение n-того элемента в списке (нумерация от 1), не удаляя этот элемент.
// Возвращает значение, которое лежит в этом элементе.
Value getNthValue(LinkedList* list, int n, ErrorCodes* errorCode);

// Проверить список на пустоту.
bool isEmpty(LinkedList* list, ErrorCodes* errorCode);

// Удалить все элементы из списка, но не удалять список.
// Нигде не сохраняет удаляемые значения.
void clearList(LinkedList* list, ErrorCodes* errorCode);

// Удалить список.
void deleteLinkedList(LinkedList* list, ErrorCodes* errorCode);
