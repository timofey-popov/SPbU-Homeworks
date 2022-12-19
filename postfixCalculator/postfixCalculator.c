#include "postfixCalculator.h"

#include <stdio.h>
#include "../customStack/customStack.h"

void getTwoValues(Stack* stackForExpression, int* firstValue, int* secondValue, CalculatorErrors* calculatorErrorCode) {
    StackErrors errorCheck = 0;

    *secondValue = pop(stackForExpression, &errorCheck);
    if (errorCheck) {
        *calculatorErrorCode = errorInStack;
        return;
    }

    *firstValue = pop(stackForExpression, &errorCheck);
    if (errorCheck) {
        *calculatorErrorCode = errorInStack;
        return;
    }
}

bool checkStackError(StackErrors* stackError, CalculatorErrors* mainErrorCode, Stack* stack) {
    if (*stackError) {
        *mainErrorCode = errorInStack;
        deleteStack(stack, stackError);
        return true;
    }

    return false;
}

int postfixCalculator(CalculatorErrors* errorCode) {
    StackErrors stackErrorCode = noErrors;
    CalculatorErrors calculatorErrorCode = noCalculatorErrors;

    Stack* stackForExpression = createStack(&stackErrorCode);
    if (stackErrorCode || stackForExpression == NULL) {
        *errorCode = errorInStack;
        return -1;
    }

    bool areThereFurtherCharacters = true;

    int firstValue = 0;
    int secondValue = 0;

    while (areThereFurtherCharacters) {
        int token = getchar();
        bool wereThereActions = true;

        if (token >= (int)'0' && token <= (int)'9') {
            push((int)token - 48, stackForExpression, &stackErrorCode);
            if (checkStackError(&stackErrorCode, errorCode, stackForExpression)) {
                return -1;
            }
        }
        else {
            if (token == '+' || token == '-' || token == '*' || token == '/') {
                getTwoValues(stackForExpression, &firstValue, &secondValue, &calculatorErrorCode);
                if (calculatorErrorCode) {
                    *errorCode = errorInStack;
                    deleteStack(stackForExpression, &stackErrorCode);
                    return -1;
                }
            }

            switch (token) {
            case '+':
                push(firstValue + secondValue, stackForExpression, &stackErrorCode);
                if (checkStackError(&stackErrorCode, errorCode, stackForExpression)) {
                    return -1;
                }
                break;

            case '-':
                push(firstValue - secondValue, stackForExpression, &stackErrorCode);
                if (checkStackError(&stackErrorCode, errorCode, stackForExpression)) {
                    return -1;
                }
                break;

            case '*':
                push(firstValue * secondValue, stackForExpression, &stackErrorCode);
                if (checkStackError(&stackErrorCode, errorCode, stackForExpression)) {
                    return -1;
                }
                break;

            case '/':
                push(firstValue / secondValue, stackForExpression, &stackErrorCode);
                if (checkStackError(&stackErrorCode, errorCode, stackForExpression)) {
                    return -1;
                }
                break;

            case ' ':
                break;

            case '\n':
                areThereFurtherCharacters = false;
                break;

            default:
                wereThereActions = false;
                break;
            }
        }

        if (!wereThereActions) {
            *errorCode = invalidInput;
            deleteStack(stackForExpression, &stackErrorCode);
            return -1;
        }
    }

    int valueToReturn = pop(stackForExpression, &stackErrorCode);
    if (checkStackError(&stackErrorCode, errorCode, stackForExpression)) {
        return -1;
    }

    if (!isEmpty(stackForExpression, &stackErrorCode)) {
        *errorCode = invalidInput;
        deleteStack(stackForExpression, &stackErrorCode);
        return -1;
    }

    return valueToReturn;
}