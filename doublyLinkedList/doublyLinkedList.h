#pragma once

// Коды ошибок:
// 
typedef enum ErrorCodes {
    noErrors,
    createListMemoryError,
    pushToHeadGotNullPointer,
    pushToHeadMemoryError,
    pushToTailGotNullPointer,
    pushToTailMemoryError,
    insertNthElementGotNullPointer,
    noSuchNumberInList,
    insertNthElementMemoryError,
    popFromHeadGotNullPointer,
    popFromHeadGotEmptyList,
    popFromTailGotNullPointer,
    popFromTailGotEmptyList,
    popNthElementGotNullPointer,
    popNthElementGotEmptyList,
    getNthValueGotNullPointer,
    getNthValueGotEmptyList
} ErrorCodes;

// Тип данных, хранящихся в списке. Если нужно его поменять - меняй здесь.
typedef int Value;

// АТД структура "двусвязный список".
typedef struct LinkedList LinkedList;

// Создать список.
// Возвращает указатель на созданный список.
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