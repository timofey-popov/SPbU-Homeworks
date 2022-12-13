#include "postfixCalculator.h"

#include <stdio.h>
#include "../customStack/customStack.h"

void getTwoValues(Stack* stackForExpression, int* firstValue, int* secondValue, CalculatorErrors* calculatorErrorCode) {
    int errorCheck = 0;

    *secondValue = pop(stackForExpression, &errorCheck);
    if (errorCheck) {
        *calculatorErrorCode = popError;
        return;
    }

    *firstValue = pop(stackForExpression, &errorCheck);
    if (errorCheck) {
        *calculatorErrorCode = popError;
        return;
    }
}

int postfixCalculator(CalculatorErrors* errorCode) {
    StackErrors stackErrorCode = noErrors;
    CalculatorErrors calculatorErrorCode = noCalculatorErrors;

    Stack* stackForExpression = createStack(&stackErrorCode);
    if (stackErrorCode || stackForExpression == NULL) {
        *errorCode = stackCreationError;
        return -1;
    }

    bool areThereFurtherCharacters = true;

    int firstValue = 0;
    int secondValue = 0;

    while (areThereFurtherCharacters) {
        int token = getchar();
        bool wereThereActions = false;
        
        switch (token) {
        case '+':
            getTwoValues(stackForExpression, &firstValue, &secondValue, &calculatorErrorCode);
            if (calculatorErrorCode) {
                deleteStack(stackForExpression, &stackErrorCode);
                return -1;
            }

            push(firstValue + secondValue, stackForExpression, &stackErrorCode);
            if (stackErrorCode) {
                *errorCode = pushError;
                deleteStack(stackForExpression, &stackErrorCode);
                return -1;
            }
            wereThereActions = true;
            break;

        case '-':
            getTwoValues(stackForExpression, &firstValue, &secondValue, &calculatorErrorCode);
            if (calculatorErrorCode) {
                deleteStack(stackForExpression, &stackErrorCode);
                return -1;
            }

            push(firstValue - secondValue, stackForExpression, &stackErrorCode);
            if (stackErrorCode) {
                *errorCode = pushError;
                deleteStack(stackForExpression, &stackErrorCode);
                return -1;
            }
            wereThereActions = true;
            break;

        case '*':
            getTwoValues(stackForExpression, &firstValue, &secondValue, &calculatorErrorCode);
            if (calculatorErrorCode) {
                deleteStack(stackForExpression, &stackErrorCode);
                return -1;
            }

            push(firstValue * secondValue, stackForExpression, &stackErrorCode);
            if (stackErrorCode) {
                *errorCode = pushError;
                deleteStack(stackForExpression, &stackErrorCode);
                return -1;
            }
            wereThereActions = true;
            break;

        case '/':
            getTwoValues(stackForExpression, &firstValue, &secondValue, &calculatorErrorCode);
            if (calculatorErrorCode) {
                deleteStack(stackForExpression, &stackErrorCode);
                return -1;
            }

            push(firstValue / secondValue, stackForExpression, &stackErrorCode);
            if (stackErrorCode) {
                *errorCode = pushError;
                deleteStack(stackForExpression, &stackErrorCode);
                return -1;
            }
            wereThereActions = true;
            break;

        case ' ':
            wereThereActions = true;
            break;

        case '\n':
            wereThereActions = true;
            areThereFurtherCharacters = false;
            break;

        default:
            break;
        }

        if (token >= 48 && token <= 57) {
            push((int)token - 48, stackForExpression, &stackErrorCode);
            if (stackErrorCode) {
                *errorCode = pushError;
                deleteStack(stackForExpression, &stackErrorCode);
                return -1;
            }
        }
        else if (!wereThereActions) {
            *errorCode = ivalidInput;
            deleteStack(stackForExpression, &stackErrorCode);
            return -1;
        }
    }

    int valueToReturn = pop(stackForExpression, &stackErrorCode);
    if (stackErrorCode) {
        *errorCode = popError;
        deleteStack(stackForExpression, &stackErrorCode);
        return -1;
    }

    if (!isEmpty(stackForExpression, &stackErrorCode)) {
        *errorCode = ivalidInput;
        deleteStack(stackForExpression, &stackErrorCode);
        return -1;
    }

    return valueToReturn;
}