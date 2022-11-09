#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Функция обработки пользовательского ввода.
// Считывает строку в указанный массив, проверяет, удалось ли что-то считать, если нет - просит повторить ввод.
void userInput(char* stringForRecord) {
    bool isInputCorrect = scanf_s("%s", stringForRecord, 1001) != 0;

    while (!isInputCorrect) {
        scanf_s("%*[^\n]");
        printf("You've entered incorrect string.\nPlease, try again:\n");
        isInputCorrect = scanf_s("%s", stringForRecord, 1001);
    }
    scanf_s("%*[^\n]");

    return;
}

// Функция подсчёта вхождений.
// На вход принимает указатели на две строки, возвращает количество вхождений второй строки в первую.
int countingFunction(char* mainString, char* substring) {
    const size_t mainStringLength = strlen(mainString);
    const size_t substringLength = strlen(substring);

    int valueToReturn = 0;

    for (size_t i = 0; i < (mainStringLength - substringLength + 1); ++i) {
        unsigned secondaryCounter = 0;

        for (size_t j = 0; j < substringLength; ++j) {
            if (mainString[i + j] == substring[j]) {
                secondaryCounter++;
            }
            else {
                break;
            }
        }

        if (secondaryCounter == substringLength) {
            valueToReturn++;
        }
    }

    return valueToReturn;
}

int main(void) {
    char mainString[1001] = { 0 };
    char substring[1001] = { 0 };

    printf("Enter the main string\n(no more than 1000 characters):\n");
    userInput(mainString);

    printf("Enter the substring\n(no more than 1000 characters):\n");
    userInput(substring);

    while (strlen(substring) > strlen(mainString)) {
        printf("Substring must be shorter than the main string. Try again.\n");

        printf("Enter the main string\n(no more than 1000 characters):\n");
        userInput(mainString);

        printf("Enter the substring\n(no more than 1000 characters):\n");
        userInput(substring);
    }

    int resultCounter = countingFunction(mainString, substring);

    printf("\nMatches found: %d\n", resultCounter);

    return 0;
}
