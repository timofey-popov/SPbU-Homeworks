#include "upgradedParenthesesBalance.h"

#include <stdio.h>
#include "../customStack/customStack.h"

// Проверяет, вернула ли операция со стеком ошибку.
// Если да - меняет глобальный код ошибки, удаляет стек и возвращает true;
// Иначе возвращает false.
bool checkStackError(StackErrors* stackError, BalanceErrorCode* mainErrorCode, Stack* stack) {
    if (*stackError) {
        *mainErrorCode = errorInStack;
        deleteStack(stack, stackError);
        return true;
    }

    return false;
}

bool upgradedParenthesesBalance(char* string, BalanceErrorCode* errorCode) {
    StackErrors stackError = noErrors;

    Stack* stackForParentheses = createStack(&stackError);
    if (stackError || stackForParentheses == NULL) {
        *errorCode = errorInStack;
        return false;
    }

    int iterator = 0;
    char token = ' ';

    while (token != '\0') {
        token = string[iterator];

        if (token == '(' || token == '[' || token == '{') {
            push((int)token, stackForParentheses, &stackError);
            if (checkStackError(&stackError, errorCode, stackForParentheses)) {
                return false;
            }
        }

        if (token == ')' || token == ']' || token == '}') {
            if (isEmpty(stackForParentheses, &stackError)) {
                deleteStack(stackForParentheses, &stackError);
                return false;
            }

            char previosParenthesis = pop(stackForParentheses, &stackError);
            if (checkStackError(&stackError, errorCode, stackForParentheses)) {
                return false;
            }

            switch (token) {
            case ')':
                if (previosParenthesis != '(') {
                    deleteStack(stackForParentheses, &stackError);
                    return false;
                }
                break;
            case ']':
                if (previosParenthesis != '[') {
                    deleteStack(stackForParentheses, &stackError);
                    return false;
                }
                break;
            case '}':
                if (previosParenthesis != '{') {
                    deleteStack(stackForParentheses, &stackError);
                    return false;
                }
                break;
            }
        }

        iterator++;
    }

    bool emptinessCheck = isEmpty(stackForParentheses, &stackError);
    if (checkStackError(&stackError, errorCode, stackForParentheses)) {
        return false;
    }

    if (!emptinessCheck) {
        deleteStack(stackForParentheses, &stackError);
        return false;
    }

    deleteStack(stackForParentheses, &stackError);
    return true;
}
