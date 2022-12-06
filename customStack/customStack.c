#include "customStack.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Структура для элемента стека.
// Содержит два поля: значение и указатель на предыдущую единицу стека.
typedef struct StackElement {
    Value value;
    struct StackElement* previous;
} StackElement;

// Структура "стек". Представляет собой указатель на голову стека.
typedef struct Stack {
    StackElement* head;
} Stack;

Stack* createStack(ErrorCodes* errorCode) {
    Stack* newStack = malloc(sizeof(Stack));

    if (newStack == NULL) {
        *errorCode = createStackMemoryError;
        return NULL;
    }

    newStack->head = NULL;

    return newStack;
}

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

Value pop(Stack* stack, ErrorCodes* errorCode) {
    if (stack == NULL) {
        *errorCode = popGotNullPointer;
        return -1;
    }

    if (stack->head == NULL) {
        *errorCode = popStackHasNoElemens;
        return -1;
    }

    Value valueToReturn = stack->head->value;
    StackElement* temporaryAddress = stack->head->previous;

    free(stack->head);
    stack->head = temporaryAddress;

    return valueToReturn;
}

void clear(Stack* stack, ErrorCodes* errorCode) {
    if (stack == NULL) {
        *errorCode = clearGotNullPointer;
        return;
    }

    while (stack->head != NULL) {
        pop(stack, errorCode);
    }
}

bool isEmpty(Stack* stack, ErrorCodes* errorCode) {
    if (stack == NULL) {
        *errorCode = isEmptyGotNullPointer;
        return false;
    }

    return stack->head == NULL;
}

void deleteStack(Stack* stack, ErrorCodes* errorCode) {
    if (stack == NULL) {
        *errorCode = deleteStackGotNullPointer;
        return;
    }

    clear(stack, errorCode);
    free(stack);
}

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
