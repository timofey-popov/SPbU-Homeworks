#include "postfixCalculator.h"

#include <stdio.h>
#include "../customStack/customStack.h"

// Записать два верхних значения из стека в две переменные.
// На вход нужен указатель на стек, два указателя на переменные для записи и указатель на переменную с кодом ошибки.
// Извлекает два значения, а если не удаётся - меняет код ошибки и заканчивает работу.
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

// Проверяет, вернула ли операция со стеком ошибку.
// Если да - меняет код ошибки калькулятора на errorInStack, удаляет стек и возвращает true;
// Иначе возвращает false.
bool checkStackError(StackErrors* stackError, CalculatorErrors* mainErrorCode, Stack* stack) {
    if (*stackError) {
        *mainErrorCode = errorInStack;
        deleteStack(stack, stackError);
        return true;
    }

    return false;
}

// Постфиксный калькулятор. 
// На вход принимает указатели на массив с выражением и на переменную с кодом ошибки.
// Возвращает целочисленный результат, если всё хорошо, и -1, если встретилась ошибка.
int postfixCalculator(char* inputArray, CalculatorErrors* errorCode) {
    StackErrors stackErrorCode = noErrors;
    CalculatorErrors calculatorErrorCode = noCalculatorErrors;

    Stack* stackForExpression = createStack(&stackErrorCode);
    if (stackErrorCode || stackForExpression == NULL) {
        *errorCode = errorInStack;
        return -1;
    }

    int firstValue = 0;
    int secondValue = 0;

    int counter = 0;
    char token = ' ';

    // Цикл считывания символов из массива.
    // Для разных символов делает разные действия.
    while (counter < 100) {
        bool wereThereActions = true;

        // Считываем токен из массива.
        token = inputArray[counter];

        if (token >= '0' && token <= '9') {
            push(token - '0', stackForExpression, &stackErrorCode);
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
                break;

            default:
                wereThereActions = false;
                break;
            }
        }

        // Этот if сработает в том случае, если считанный символ не является ни цифрой, ни оператором, ни пробелом или переводом строки.
        if (!wereThereActions) {
            *errorCode = invalidInput;
            deleteStack(stackForExpression, &stackErrorCode);
            return -1;
        }

        if (token == '\n') {
            break;
        }

        counter++;
    }

    // Если дошли до 100-го символа и не встретили перевода строки - говорим, что во вводе ошибка.
    if (counter == 100 && inputArray[counter - 1] != '\n') {
        deleteStack(stackForExpression, &stackErrorCode);
        *errorCode = invalidInput;
        return -1;
    }

    int valueToReturn = pop(stackForExpression, &stackErrorCode);
    if (checkStackError(&stackErrorCode, errorCode, stackForExpression)) {
        return -1;
    }
    
    // Если в стеке что-то осталось - значит, что-то пошло не так, как ожидалось.
    if (!isEmpty(stackForExpression, &stackErrorCode)) {
        *errorCode = invalidInput;
        deleteStack(stackForExpression, &stackErrorCode);
        return -1;
    }

    deleteStack(stackForExpression, &stackErrorCode);
    return valueToReturn;
}
