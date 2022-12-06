#include "customStack.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Структура для единицы стека.
// Содержит два поля: значение и указатель на предыдущую единицу стека.
typedef struct StackElement {
    Value value;
    struct StackElement* previous;
} StackElement;

// Структукра "стек". Представляет собой указатель на глову стека.
typedef struct Stack {
    StackElement* head;
} Stack;

// Создаёт пустой стек.
// На вход принимает указатель на переменную с кодом ошибки.
// Возвращает указатель на стек, если всё прошло нормально,в противном случае возвращает NULL и меняет код ошибки на 1.
Stack* createStack(ErrorCodes* errorCode) {
    Stack* newStack = malloc(sizeof(Stack));

    if (newStack == NULL) {
        *errorCode = createStackMemoryError;
        return NULL;
    }

    newStack->head = NULL;

    return newStack;
}

// Добавляет элемент на верхушку стека.
// На вход принимает добавляемое значение, указатель на стек и указатель на переменную с кодом ошибки.
void push(Value value, Stack* stack, ErrorCodes* errorCode) {
    if (stack == NULL) {
        *errorCode = pushGotNullPointer;
        return;
    }

    StackElement* newHead = malloc(sizeof(StackElement));

    if (newHead == NULL) {
        *errorCode = pushMemoryError;
        return;
    }

    newHead->previous = stack->head;
    newHead->value = value;

    stack->head = newHead;
}

// Удаляет элемент с вершины стека и возвращает значение, которое в нём лежало.
// На вход принимает указатель на стек и указатель на переменную с кодом ошибки.
Value pop(Stack* stack, ErrorCodes* errorCode) {
    if (stack == NULL) {
        *errorCode = popGotNullPointer;
        return NULL;
    }

    if (stack->head == NULL) {
        *errorCode = popStackHasNoElemens;
        return NULL;
    }

    Value valueToReturn = stack->head->value;
    StackElement* temporaryAddress = stack->head->previous;

    free(stack->head);
    stack->head = temporaryAddress;

    return valueToReturn;
}

// Удаляет все элементы из стека, никуда их не сохраняя.
// На вход принимает указатель на стек и указатель на переменную с кодом ошибки.
void clear(Stack* stack, ErrorCodes* errorCode) {
    if (stack == NULL) {
        *errorCode = clearGotNullPointer;
        return;
    }

    while (stack->head != NULL) {
        pop(stack, errorCode);
    }
}

// Функция проверки стека на пустоту.
// На вход принимает указатель на голову стека.
// Возвращает true, если стек пуст, и false в противном случае.
bool isEmpty(Stack* stack, ErrorCodes* errorCode) {
    if (stack == NULL) {
        *errorCode = isEmptyGotNullPointer;
        return NULL;
    }

    return stack->head == NULL;
}

// Удалить указанный стек.
void deleteStack(Stack* stack, ErrorCodes* errorCode) {
    if (stack == NULL) {
        *errorCode = deleteStackGotNullPointer;
        return;
    }

    clear(stack, errorCode);
    free(stack);
}

// Печатает все значения в стеке как целые числа, начиная от головы.
// Если на вход передан NULL, печатает предупреждение в консоль и меняет код ошибки на 1.
void printStack(Stack* stack, ErrorCodes* errorCode) {
    if (stack == NULL) {
        *errorCode = printStackGotNullPointer;
        printf("There's no stack\n\n");
        return;
    }

    if (stack->head == NULL) {
        printf("Stack is empty\n\n");
        return;
    }

    StackElement* headCopy = stack->head;

    while (headCopy != NULL) {
        printf("%d\n", headCopy->value);
        headCopy = headCopy->previous;
    }
    printf("\n");
}
