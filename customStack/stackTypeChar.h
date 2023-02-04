#pragma once

#include <stdbool.h>

// Коды ошибок:
// 0 - нет ошибок.
// 1 - ошибка выделения памяти.
// 2 - в качестве указателя на голову стека передан NULL.
// 3 - в стеке нет элементов.
typedef enum StackErrors {
    noErrors,
    memoryAllocationError,
    nullPointerReceived,
    noElemensInStack,
} StackErrors;

// Тип переменных для хранения в элементах стека.
// Если нужно поменять - меняем тип данных в этом месте.
typedef char Value;

// Абстрактный тип данных "стек".
typedef struct Stack Stack;

// Создаёт пустой стек.
// На вход принимает указатель на переменную с кодом ошибки.
// Возвращает указатель на стек, если всё прошло нормально,в противном случае возвращает NULL.
// В случае ошибки стек не создаётся, удалять его не нужно.
Stack* createStack(StackErrors* errorCode);

// Добавляет элемент на верхушку стека.
// На вход принимает добавляемое значение, указатель на стек и указатель на переменную с кодом ошибки.
void push(Value value, Stack* stack, StackErrors* errorCode);

// Получить верхний элемент стека не удаляя его.
Value get(Stack* stack, StackErrors* errorCode);

// Удаляет элемент с вершины стека и возвращает значение, которое в нём лежало.
// На вход принимает указатель на стек и указатель на переменную с кодом ошибки.
Value pop(Stack* stack, StackErrors* errorCode);

// Удаляет все элементы из стека, никуда их не сохраняя.
// На вход принимает указатель на стек и указатель на переменную с кодом ошибки.
void clear(Stack* stack, StackErrors* errorCode);

// Возвращает true, если стек пуст, и false в противном случае.
// Если в качестве указателя на стек передан NULL, возвращает false и меняет код ошибки.
bool isEmpty(Stack* stack, StackErrors* errorCode);

// Удалить указанный стек.
void deleteStack(Stack* stack, StackErrors* errorCode);

// Печатает все значения в стеке как целые числа, начиная от головы.
// Если на вход передан NULL, печатает предупреждение в консоль и меняет код ошибки.
void printStack(Stack* stack, StackErrors* errorCode);
