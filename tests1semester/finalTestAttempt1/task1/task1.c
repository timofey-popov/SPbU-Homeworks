#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void getDecimalString(char* initialString, char* stringForResult, size_t stringSize, bool* errorCode) {
    // Переменная, которая будет представлять нужную степень двойки, от 2^0 до 2^(n - 1), где n - длина строки.
    int multiplier = 1;
    int decimalResult = 0;

    bool error = false;

    for (int i = (int)stringSize - 1; i >= 0; --i) {
        char symbol = initialString[i];

        switch (symbol) {
        case '1':
            decimalResult += multiplier;
            multiplier *= 2;
            break;

        case '0':
            multiplier *= 2;
            break;

        default:
            error = true;
            break;
        }
    }

    if (error) {
        *errorCode = true;
        return;
    }

    sprintf_s(stringForResult, stringSize + 1, "%d", decimalResult);
}

bool test(void) {
    char* testString1 = "0";
    char* testString2 = "101010111100";

    char* testResult1[2];
    char* testResult2[13];

    bool errorCode = false;

    getDecimalString(testString1, testResult1, 1, &errorCode);
    getDecimalString(testString2, testResult2, 12, &errorCode);

    if (errorCode || strcmp(testResult1, "0") || strcmp(testResult2, "2748")) {
        return false;
    }

    return true;
}

int main(void) {
    if (!test()) {
        printf("Test failed\n");
        return -1;
    }
    printf("*test passed*\n\n");

    char* initialString = "11001010";
    size_t stringSize = strlen(initialString);
    if (stringSize < 1) {
        printf("String is too short\n");
        return 0;
    }

    char* stringForResult = calloc(stringSize + 1, sizeof(char));

    bool errorCode = false;
    getDecimalString(initialString, stringForResult, stringSize, &errorCode);
    if (errorCode) {
        printf("Unknown symbols\n");
        return -1;
    }

    printf("Result: %s\n", stringForResult);

    return 0;
}
