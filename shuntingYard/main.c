#include "shuntingYard.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

bool tests(void) {
    char* testInputString1 = "( 1 + 1 ) * 2";
    char* testInputString2 = "3 + 4 * 2 / ( 1 - 5 )";

    size_t arraySize1 = strlen(testInputString1);
    size_t arraySize2 = strlen(testInputString2);

    char* outputString1 = calloc(arraySize1, sizeof(char));
    if (outputString1 == NULL) {
        return false;
    }
    char* outputString2 = calloc(arraySize2, sizeof(char));
    if (outputString2 == NULL) {
        free(outputString1);
        return false;
    }

    ShuntingYardErrors testErrorCode = noErrorsInYard;

    shuntingYard(testInputString1, outputString1, arraySize1, &testErrorCode);
    shuntingYard(testInputString2, outputString2, arraySize2, &testErrorCode);

    if (testErrorCode) {
        free(outputString1);
        free(outputString2);
        return false;
    }

    char* referenceArray1 = "11+2*";
    char* referenceArray2 = "342*15-/+";

    size_t lengthOfReferenceArray1 = 5;
    for (size_t i = 0; i < lengthOfReferenceArray1; ++i) {
        if (referenceArray1[i] != outputString1[i]) {
            free(outputString1);
            free(outputString2);
            return false;
        }
    }

    size_t lengthOfReferenceArray2 = 9;
    for (size_t i = 0; i < lengthOfReferenceArray2; ++i) {
        if (referenceArray2[i] != outputString2[i]) {
            free(outputString1);
            free(outputString2);
            return false;
        }
    }

    free(outputString1);
    free(outputString2);
    return true;
}

int main(void) {
    if (!tests()) {
        printf("Tests failed\n\n");
        return -1;
    }
    printf("*tests passed*\n\n");

    // —юда вводить строку.
    char* inputString = "6 * ((4 + 2) / 3) - (3 - 1)";
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