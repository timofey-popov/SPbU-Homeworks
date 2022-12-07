#pragma once

typedef enum ErrorCodes {
    noErrors,
    memoryAllocationError,
    nullPointerReceived,
    treeIsEmpty,

} ErrorCodes;

typedef int Value;

typedef struct AVLTree AVLTree;