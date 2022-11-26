#pragma once

#include <stdbool.h>

// Коды ошибок:
// 1 - ошибка выделения памяти под новый стек (createStack).
// 2 - в качестве указателя на голову стека передан NULL (push).
// 3 - ошибка выделения памяти под новый элемент стека (push).
// 4 - в качестве указателя на голову стека передан NULL (pop).
// 5 - в стеке нет элеменетов для pop (pop).
// 6 - в качестве указателя на голову стека передан NULL (clear).
// 7 - в качестве указателя на голову стека передан NULL (isEmpty).
// 8 - в качестве указателя на голову стека передан NULL (deleteStack).
// 9 - в качестве указателя на голову стека передан NULL (printStack).
typedef enum ErrorCodes {
    noErrors,
    createStackMemoryError,
    pushGotNullPointer,
    pushMemoryError,
    popGotNullPointer,
    popStackHasNoElemens,
    clearGotNullPointer,
    isEmptyGotNullPointer,
    deleteStackGotNullPointer,
    printStackGotNullPointer,
} ErrorCodes;

// Тип переменных для хранения в элементах стека.
// Если нужно поменять - меняем тип данных в этом месте.
typedef int Value;

// Абстрактный тип данных "стек".
typedef struct Stack Stack;

// Создаёт пустой стек.
// На вход принимает указатель на переменную с кодом ошибки.
// Возвращает указатель на стек, если всё прошло нормально,в противном случае возвращает NULL и меняет код ошибки на 1.
Stack* createStack(ErrorCodes* errorCode);

// Добавляет элемент на верхушку стека.
// На вход принимает добавляемое значение, указатель на стек и указатель на переменную с кодом ошибки.
void push(Value value, Stack* stack, ErrorCodes* errorCode);

// Удаляет элемент с вершины стека и возвращает значение, которое в нём лежало.
// На вход принимает указатель на стек и указатель на переменную с кодом ошибки.
Value pop(Stack* stack, ErrorCodes* errorCode);

// Удаляет все элементы из стека, никуда их не сохраняя.
// На вход принимает указатель на стек и указатель на переменную с кодом ошибки.
void clear(Stack* stack, ErrorCodes* errorCode);

// Возвращает true, если стек пуст, и false в противном случае.
// Если в качестве указателя на стек передан NULL, возвращает false и меняет код ошибки на 7.
bool isEmpty(Stack* stack, ErrorCodes* errorCode);

// Удалить указанный стек.
void deleteStack(Stack* stack, ErrorCodes* errorCode);

// Печатает все значения в стеке как целые числа, начиная от головы.
// Если на вход передан NULL, печатает предупреждение в консоль и меняет код ошибки на 9.
void printStack(Stack* stack, ErrorCodes* errorCode);
