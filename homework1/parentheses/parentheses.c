#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Функция проверки баланса скобок.
// На вход принимает указатель на строку со скобками и размер этой строки.
// Возвращает true, если баланс корректный и false в противном случае.
bool parenthesesBalance(char* inputString, size_t arraySize) {
    int counter = 0;

    for (size_t i = 0; i < arraySize; ++i) {
        if (counter < 0) {
            return false;
        }

        if (inputString[i] == '(') {
            counter += 1;
        } else if (inputString[i] == ')') {
            counter -= 1;
        }
    }

    return counter == 0;
}

int main(void) {
    char userInput[1000] = { 0 };
    const size_t arraySize = sizeof(userInput) / sizeof(char);

    printf("Enter a string with parentheses:\n");
    int correctnessCheck = scanf("%s", userInput);

    printf(parenthesesBalance(userInput, arraySize) ? "\nThe balance is correct\n" : "\nThe balance is NOT correct\n");

    return 0;
}