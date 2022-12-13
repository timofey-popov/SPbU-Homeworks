#include "postfixCalculator.h"

#include "../customStack/customStack.h"
#include <stdio.h>

void inputExpression(Stack* stackForExpression) {

}

int add(Stack* stackForExpression, ErrorCodes* stackErrorCode) {
    int secondSummand = pop(stackForExpression, *stackErrorCode);
    if (stackErrorCode) {
        *errorCode = popError;
        return 0;
    }

    int firstSummand = pop(stackForExpression, &stackErrorCode);
    if (stackErrorCode) {
        *errorCode = popError;
        return 0;
    }
}

int postfixCalculator(CalculatorErrors* errorCode) {
    StackErrors stackErrorCode = noErrors;
    CalculatorErrors calculatorErrorCode = noErrors;

    Stack* stackForExpression = createStack(&stackErrorCode);
    if (stackErrorCode || stackForExpression == NULL) {
        *errorCode = stackCreationError;
        return 0;
    }

    int valueToReturn = 0;
    bool areThereFurtherCharacters = true;

    while (areThereFurtherCharacters) {
        int token = getchar();
        
        if (token == '+') {
            
        }
    }

    return 0;
}