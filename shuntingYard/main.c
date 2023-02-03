#include "shuntingYard.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main(void) {
    char* inputString = "(1+1)*2";
    size_t arraySize = strlen(inputString);

    char* outputString = calloc(arraySize, sizeof(char));
    if (outputString == NULL) {
        printf("Memory error\n");
        return -1;
    }

    ShuntingYardErrors errorCode = noErrorsInYard;

    shuntingYard(inputString, outputString, arraySize, &errorCode);

    for (size_t i = 0; i < arraySize; ++i) {
        printf("%c ", outputString[i]);
    }
    printf("\n");

    return 0;
}