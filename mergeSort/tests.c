#include "tests.h"
#include "mergeSort.h"

#include <string.h>

// Добавляет значения из массива в список по порядку. Возвращает количество успешно добавленных элементов.
int arrayToList(int* array, int arrayLength, List* list) {
    ListErrors errorCode = noErrorsInList;
    int successfullOperationsCounter = 0;

    for (int i = 0; i < arrayLength; ++i) {
        addElement(array[i], list, &errorCode);
        if (!(errorCode)) {
            successfullOperationsCounter++;
        }
        else {
            return successfullOperationsCounter;
        }
    }

    return successfullOperationsCounter;
}

// Добавляет значения из списка в массив по порядку. Возвращает количество успешно добавленных элементов.
int listToArray(List* list, int listLength, int* array) {
    ListErrors errorCode = noErrorsInList;
    int successfullOperationsCounter = 0;

    for (int i = 0; i < listLength; ++i) {
        array[i] = getNthValue(list, i + 1, &errorCode);
        if (!(errorCode)) {
            successfullOperationsCounter++;
        }
        else {
            return successfullOperationsCounter;
        }
    }

    return successfullOperationsCounter;
}

// Сортирует массив посредством перевода его в список и применения mergeSort к списку. 
// Перезаписывает переданный на вход массив.
// Возвращает true, если всё прошло нормально, и false в противном случае.
bool mergeSortForArrays(int* array, int length) {
    ListErrors errorCode = noErrorsInList;

    List* listForSort = createList(&errorCode);
    if (errorCode) {
        return false;
    }

    int arrayToListCheck = arrayToList(array, length, listForSort);
    if (arrayToListCheck != length) {
        deleteList(listForSort, &errorCode);
        return false;
    }

    List* result = mergeSort(listForSort, &errorCode);
    if (errorCode) {
        deleteList(result, &errorCode);
        deleteList(listForSort, &errorCode);
        return false;
    }

    int listToArrayCheck = listToArray(result, length, array);

    deleteList(result, &errorCode);
    deleteList(listForSort, &errorCode);

    return listToArrayCheck == length && !errorCode;
}

bool testForMergeSort(void) {
    // Обратный порядок, ноль, положительные и отрицательные.
    int input1[] = { 2, 1, 0, -1, -2 };
    // Уже отсортирован.
    int input2[] = { -5, -4, 0, 19, 100 };
    // Одинаковые элементы.
    int input3[] = { 5, 5, 5, 5, 5, 5 };
    // Обычный случай.
    int input4[] = { 14, 3, -5, 21, 13, 0, -128, 1 };

    int referenceArray1[] = { -2, -1, 0, 1, 2 };
    int referenceArray2[] = { -5, -4, 0, 19, 100 };
    int referenceArray3[] = { 5, 5, 5, 5, 5, 5 };
    int referenceArray4[] = { -128, -5, 0, 1, 3, 13, 14, 21 };

    bool sortCheck1 = mergeSortForArrays(input1, 5);
    bool sortCheck2 = mergeSortForArrays(input2, 5);
    bool sortCheck3 = mergeSortForArrays(input3, 6);
    bool sortCheck4 = mergeSortForArrays(input4, 8);
    if (!sortCheck1 || !sortCheck2 || !sortCheck3 || !sortCheck4) {
        return false;
    }

    int resultCheck1 = memcmp(input1, referenceArray1, sizeof(int) * 5);
    int resultCheck2 = memcmp(input2, referenceArray2, sizeof(int) * 5);
    int resultCheck3 = memcmp(input3, referenceArray3, sizeof(int) * 6);
    int resultCheck4 = memcmp(input4, referenceArray4, sizeof(int) * 8);

    return !resultCheck1 && !resultCheck2 && !resultCheck3 && !resultCheck4;
}
