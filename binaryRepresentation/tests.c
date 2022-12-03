#include <stdio.h>
#include <stdbool.h>
#include "binaryRepresentation.h"

bool testForCreateBinary(void) {
    int testBinaries[3][NUMBER_OF_DIGITS] = { { 0 }, { 0 }, { 0 } };
    int testBinaryReferences2[3][8] = { { 0, 1, 0, 1, 0, 0, 0, 0 }, { 1, 0, 1, 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0 } };

    createBinary(10, testBinaries[0]);
    createBinary(-11, testBinaries[1]);
    createBinary(0, testBinaries[2]);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (testBinaries[i][j] != testBinaryReferences2[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool testForCreateDecimal(void) {
    int testBinaries[3][NUMBER_OF_DIGITS] = { { 0 }, { 0 }, { 0 } };
    int testDecimals[3] = { 0 };
    int testDecimalReferences[] = { 0, 50164, -90533 };

    // Так как предыдущий тест не сломался, предполагаем, что createBinary работает верно.
    createBinary(0, testBinaries[0]);
    createBinary(50164, testBinaries[1]);
    createBinary(-90533, testBinaries[2]);

    for (int i = 0; i < 3; ++i) {
        testDecimals[i] = createDecimal(testBinaries[i]);

        if (testDecimals[i] != testDecimalReferences[i]) {
            return false;
        }
    }

    return true;
}

bool testForAddBinary(void) {
    int firstBinarySummands[3][NUMBER_OF_DIGITS] = { { 0 }, { 0 }, { 0 } };
    int secondBinarySummands[3][NUMBER_OF_DIGITS] = { { 0 }, { 0 }, { 0 } };

    createBinary(-510, firstBinarySummands[1]);
    createBinary(984, secondBinarySummands[1]);

    createBinary(-300, firstBinarySummands[2]);
    createBinary(-1000000, secondBinarySummands[2]);

    int testBinaryReferences[3][NUMBER_OF_DIGITS] = { { 0 }, { 0 }, { 0 } };

    createBinary(474, testBinaryReferences[1]);
    createBinary(-1000300, testBinaryReferences[2]);

    int testBinaryResults[3][NUMBER_OF_DIGITS] = { { 0 }, { 0 }, { 0 } };

    for (int i = 0; i < 3; ++i) {
        addBinary(firstBinarySummands[i], secondBinarySummands[i], testBinaryResults[i]);

        for (int j = 0; j < NUMBER_OF_DIGITS; ++j) {
            if (testBinaryResults[i][j] != testBinaryReferences[i][j]) {
                return false;
            }
        }
    }

    return true;
}
