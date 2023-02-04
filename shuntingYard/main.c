#include "shuntingYard.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main(void) {
    // —юда вводить строку.
    char* inputString = "3 + 4 * 2 / ( 1 - 5 )";
    size_t arraySize = strlen(inputString);

    char* outputString = calloc(arraySize, sizeof(char));
    if (outputString == NULL) {
        printf("Memory error\n");
        return -1;
    }

    ShuntingYardErrors errorCode = noErrorsInYard;

    shuntingYard(inputString, outputString, arraySize, &errorCode);
    if (errorCode) {
        free(outputString);
        printf("Error %d occured\n", errorCode);
        return errorCode;
    }

    printf("Result:\n\n");
    for (size_t i = 0; i < arraySize; ++i) {
        printf("%c ", outputString[i]);
    }
    printf("\n");

    free(outputString);
    return 0;
}