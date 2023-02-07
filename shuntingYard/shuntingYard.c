#include "shuntingYard.h"

#include "../customStack/stackTypeChar.h"

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

bool isStackError(StackErrors* stackError, Stack* stack, ShuntingYardErrors* errorCode) {
    if (*stackError) {
        *errorCode = errorInStack;
        deleteStack(stack, stackError);
        return true;
    }

    return false;
}

void shuntingYard(char* inputArray, char* outputArray, size_t arraysSize, ShuntingYardErrors* errorCode) {
    StackErrors stackError = noErrors;

    Stack* stack = createStack(&stackError);
    if ((stack == NULL) || stackError) {
        *errorCode = errorInStack;
        return;
    }

    int filledCellsCounter = 0;
    for (size_t i = 0; i < arraysSize; ++i) {
        char token = inputArray[i];
        if (isANumber(token)) {
            outputArray[filledCellsCounter] = token;
            filledCellsCounter++;
        }
        else if (isAnOperator(token)) {
            while (!isEmpty(stack, &stackError) && (get(stack, &stackError) != '(') && (getPrecedence(token) <= getPrecedence(get(stack, &stackError))) && !stackError) {
                outputArray[filledCellsCounter] = pop(stack, &stackError);
                filledCellsCounter++;
            }
            if (isStackError(&stackError, stack, errorCode)) {
                return;
            }

            push(token, stack, &stackError);
            if (isStackError(&stackError, stack, errorCode)) {
                return;
            }
        }
        else if (token == '(') {
            push(token, stack, &stackError);
            if (isStackError(&stackError, stack, errorCode)) {
                return;
            }
        }
        else if (token == ')') {
            if (isEmpty(stack, &stackError)) {
                *errorCode = wrongExpression;
                deleteStack(stack, &stackError);
                return;
            }
            if (isStackError(&stackError, stack, errorCode)) {
                return;
            }

            char previousOperator = pop(stack, &stackError);
            if (isStackError(&stackError, stack, errorCode)) {
                return;
            }

            while (previousOperator != '(') {
                outputArray[filledCellsCounter] = previousOperator;
                filledCellsCounter++;

                if (isEmpty(stack, &stackError)) {
                    *errorCode = wrongExpression;
                    deleteStack(stack, &stackError);
                    return;
                }
                if (isStackError(&stackError, stack, errorCode)) {
                    return;
                }

                previousOperator = pop(stack, &stackError);
                if (isStackError(&stackError, stack, errorCode)) {
                    return;
                }
            }
        }
        else if (token != ' ') {
            *errorCode = wrongExpression;
            deleteStack(stack, &stackError);
            return;
        }
    }

    while (!isEmpty(stack, &stackError)) {
        if (isStackError(&stackError, stack, errorCode)) {
            return;
        }

        char nextOperator = pop(stack, &stackError);
        if (isStackError(&stackError, stack, errorCode)) {
            return;
        }

        if (nextOperator == '(') {
            *errorCode = wrongExpression;
            deleteStack(stack, &stackError);
            return;
        }

        outputArray[filledCellsCounter] = nextOperator;
        filledCellsCounter++;
    }

    deleteStack(stack, &stackError);
}