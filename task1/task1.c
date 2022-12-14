#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getNumberOfCharacters(char* string) {
    bool areThereFurtherCharacters = true;
    int counter = 0;

    while (areThereFurtherCharacters) {
        if (string[counter] != '\0') {
            counter += 1;
        }
        else {
            areThereFurtherCharacters = false;
        }
    }

    return counter;
}

void getDecimalString(char* initialString, char* stringForResult, int stringSize, bool* errorCode) {
    int multiplier = 1;
    int decimal = 0;

    bool error = false;

    for (int i = stringSize - 1; i >= 0; ++i) {
        char symbol = initialString[i];

        switch (symbol) {
        case '1':
            decimal += multiplier;
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

    sprintf_s(stringForResult, "%d", decimal);
}

int main(void) {
    char* initialString = "1011100010\0";
    int stringSize = getNumberOfCharacters(initialString);

    char* stringForResult = calloc(stringSize, sizeof(char));

    bool errorCode = false;
    getDecimalString(initialString, stringForResult, stringSize, &errorCode);
    if (errorCode) {
        printf("Unknown symbols\n");
        return -1;
    }

    printf("%s\n", stringForResult);

    return 0;
}
