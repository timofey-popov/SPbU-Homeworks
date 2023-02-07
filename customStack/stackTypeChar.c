#include "stackTypeChar.h"

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

Stack* createStack(StackErrors* errorCode) {
    Stack* newStack = malloc(sizeof(Stack));

    if (newStack == NULL) {
        *errorCode = memoryAllocationError;
        return NULL;
    }

    newStack->head = NULL;

    return newStack;
}

void push(Value value, Stack* stack, StackErrors* errorCode) {
    if (stack == NULL) {
        *errorCode = nullPointerReceived;
        return;
    }

    StackElement* newHead = malloc(sizeof(StackElement));

    if (newHead == NULL) {
        *errorCode = memoryAllocationError;
        return;
    }

    newHead->previous = stack->head;
    newHead->value = value;

    stack->head = newHead;
}

Value get(Stack* stack, StackErrors* errorCode) {
    if (stack == NULL) {
        *errorCode = nullPointerReceived;
        return -1;
    }

    if (stack->head == NULL) {
        *errorCode = noElemensInStack;
        return -1;
    }

    return stack->head->value;
}

Value pop(Stack* stack, StackErrors* errorCode) {
    if (stack == NULL) {
        *errorCode = nullPointerReceived;
        return -1;
    }

    if (stack->head == NULL) {
        *errorCode = noElemensInStack;
        return -1;
    }

    Value valueToReturn = stack->head->value;
    StackElement* temporaryAddress = stack->head->previous;

    free(stack->head);
    stack->head = temporaryAddress;

    return valueToReturn;
}

void clear(Stack* stack, StackErrors* errorCode) {
    if (stack == NULL) {
        *errorCode = nullPointerReceived;
        return;
    }

    while (stack->head != NULL) {
        pop(stack, errorCode);
    }
}

bool isEmpty(Stack* stack, StackErrors* errorCode) {
    if (stack == NULL) {
        *errorCode = nullPointerReceived;
        return false;
    }

    return stack->head == NULL;
}

void deleteStack(Stack* stack, StackErrors* errorCode) {
    if (stack == NULL) {
        *errorCode = nullPointerReceived;
        return;
    }

    clear(stack, errorCode);
    free(stack);
}

void printStack(Stack* stack, StackErrors* errorCode) {
    if (stack == NULL) {
        *errorCode = nullPointerReceived;
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
