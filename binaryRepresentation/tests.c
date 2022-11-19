#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "binaryRepresentation.h"


// Тест для функции возведения двойки в положительную степень.
bool testForPositiveExponent(void) {
    return positiveExponentOfTwo(8) == 256 && positiveExponentOfTwo(0) == 1;
}

// Тест для функции создания дополнительного двоичного кода.
bool testForCreateAdditionalCode(void) {
    int testBinaries[3][8] = { { 0, 0, 0, 0, 0, 1, 0, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0 } };
    int testBinaryResults[3][8] = { { 0 }, { 0 }, { 0 } };
    int testBinaryReferences1[3][8] = { { 1, 1, 1, 1, 1, 0, 1, 1 }, { 0, 0, 0, 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0 } };


    for (int i = 0; i < 3; ++i) {
        createAdditionalCode(testBinaries[i], testBinaryResults[i]);
        
        for (int j = 0; j < 8; ++j) {
            if (testBinaryReferences1[i][j] != testBinaryResults[i][j]) {
                return false;
            }
        }
    }

    return true;
}

// Тест для функции создания двоичного кода десятичного числа.
bool testForGenerateBinary(void) {
    int testBinaries[3][8] = { { 0 }, { 0 }, { 0 } };
    int testBinaryReferences2[3][8] = { { 0, 0, 0, 0, 1, 0, 1, 0 }, { 1, 1, 1, 1, 0, 1, 0, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0 } };

    generateBinary(10, testBinaries[0]);
    generateBinary(-11, testBinaries[1]);
    generateBinary(0, testBinaries[2]);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (testBinaries[i][j] != testBinaryReferences2[i][j]) {
                return false;
            }
        }
    }

    return true;
}

// Тест для функции создания десятичного числа по его двоичному представлению в дополнительном коде.
bool testForGenerateDecimal(void) {
    int testBinaries[3][8] = { { 0, 0, 0, 1, 1, 0, 0, 1 }, { 1, 1, 1, 1, 0, 0, 1, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0 } };
    int testDecimals[3] = { 0 };
    int testDecimalReferences3[] = { 25, -13, 0 };

    for (int i = 0; i < 3; ++i) {
        generateDecimal(testBinaries[i], &testDecimals[i]);
        if (testDecimals[i] != testDecimalReferences3[i]) {
            return false;
        }
    }

    return true;
}

// Тест для функции сложения двух двоичных чисел.
bool testForAddBinaries(void) {
    int firstBinarySummands[3][8] = { { 0, 0, 1, 0, 0, 1, 0, 1 }, { 1, 1, 1, 0, 0, 0, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1 } };
    int secondBinarySummands[3][8] = { { 0, 1, 0, 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 1, 1, 1, 1, 1, 1, 1 } };
    int testBinaryResults[3][8] = { { 0 }, { 0 }, { 0 } };
    int testBinaryReferences4[3][8] = { { 0, 1, 1, 1, 0, 1, 0, 0 }, { 1, 1, 1, 0, 0, 0, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 0 } };

    for (int i = 0; i < 3; ++i) {
        addBinary(firstBinarySummands[i], secondBinarySummands[i], testBinaryResults[i]);
        for (int j = 0; j < 8; ++j) {
            if (testBinaryResults[i][j] != testBinaryReferences4[i][j]) {
                return false;
            }
        }
    }

    return true;
}