#include "shuntingYard.h"

#include "../customStack/customStack.h"
#include <stdlib.h>

int getPrecedence(char token) {
    switch (token) {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    default:
        return -1;
    }
}

bool isANumber(char token) {
    return ('0' <= token) && (token <= '9');
}

bool isAnOperator(char token) {
    return (token == '+') || (token == '-') || (token == '*') || (token == '/');
}

void shuntingYard(char* inputArray, char* outputArray, size_t arraysSize, ShuntingYardErrors* errorCode) {
    StackErrors stackError = noErrors;

    int filledCellsCounter = 0;
    Stack* stack = createStack(&stackError);
    if ((stack == NULL) || stackError) {
        *errorCode = errorInStack;
        return;
    }

    for (size_t i = 0; i < arraysSize; ++i) {
        char token = inputArray[i];
        if (isANumber(token)) {
            outputArray[filledCellsCounter] = token;
            filledCellsCounter++;
        }
        else if (isAnOperator(token)) {
            while (!isEmpty(stack, &stackError) && (get(stack, &stackError) != '(') && (getPrecedence(token) <= getPrecedence(get(stack, &stackError)))) {
                outputArray[filledCellsCounter] = pop(stack, &stackError);
                filledCellsCounter++;
            }
            push(token, stack, &stackError);
        }
        else if (token == '(') {
            push(token, stack, &stackError);
        }
        else if (token == ')') {
            if (isEmpty(stack, &stackError)) {
                *errorCode = wrongExpression;
                deleteStack(stack, &stackError);
                return;
            }

            char previousOperator = pop(stack, &stackError);
            while (previousOperator != '(') {
                outputArray[filledCellsCounter] = previousOperator;
                filledCellsCounter++;

                if (isEmpty(stack, &stackError)) {
                    *errorCode = wrongExpression;
                    deleteStack(stack, &stackError);
                    return;
                }

                previousOperator = pop(stack, &stackError);
            }

        }
    }

    while (!isEmpty(stack, &stackError)) {
        char nextOperator = pop(stack, &stackError);

        if (nextOperator == '(') {
            *errorCode = wrongExpression;
            deleteStack(stack, &stackError);
            return;
        }

        outputArray[filledCellsCounter] = nextOperator;
        filledCellsCounter++;
    }
}