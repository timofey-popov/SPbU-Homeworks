#include "mergeSort.h"

#include <stdlib.h>
#include <stdbool.h>

// Проверяет код ошибки. Если есть ошибка - удаляет два списка и возвращает true, иначе возвращает false.
bool isAnError(ListErrors* errorCode, List* listToDelete1, List* listToDelete2) {
    if (*errorCode) {
        deleteList(listToDelete1, errorCode);
        deleteList(listToDelete2, errorCode);
        return true;
    }

    return false;
}

List* merge(List* left, List* right, ListErrors* errorCode) {
    List* result = createList(errorCode);
    if (*errorCode) {
        return NULL;
    }

    while (!isEmpty(left, errorCode) && !isEmpty(right, errorCode)) {
        if (getNthValue(left, 1, errorCode) <= getNthValue(right, 1, errorCode)) {
            addElement(popNthElement(left, 1, errorCode), result, errorCode);
        }
        else {
            addElement(popNthElement(right, 1, errorCode), result, errorCode);
        }
        if (*errorCode) {
            deleteList(result, errorCode);
            return NULL;
        }
    }

    while (!isEmpty(left, errorCode)) {
        addElement(popNthElement(left, 1, errorCode), result, errorCode);
    }

    while (!isEmpty(right, errorCode)) {
        addElement(popNthElement(right, 1, errorCode), result, errorCode);
    }
    if (*errorCode) {
        deleteList(result, errorCode);
        return NULL;
    }

    return result;
}

List* mergeSort(List* listToSort, ListErrors* errorCode) {
    int listLength = getListLength(listToSort, errorCode);
    if (*errorCode) {
        return NULL;
    }

    if (listLength <= 1) {
        return listToSort;
    }

    List* left = createList(errorCode);
    if (*errorCode) {
        return NULL;
    }

    List* right = createList(errorCode);
    if (*errorCode) {
        return NULL;
    }

    // Раскладываем значения из исходного списка в два новых: левый и правый.
    for (int i = 1; i <= listLength; ++i) {
        Value ithValue = getNthValue(listToSort, i, errorCode);
        if (isAnError(errorCode, left, right)) {
            return NULL;
        }

        if (i < (listLength / 2)) {
            addElement(ithValue, left, errorCode);
            if (isAnError(errorCode, left, right)) {
                return NULL;
            }
        }
        else {
            addElement(ithValue, right, errorCode);
            if (isAnError(errorCode, left, right)) {
                return NULL;
            }
        }
    }

    left = mergeSort(left, errorCode);
    if (isAnError(errorCode, left, right)) {
        return NULL;
    }

    right = mergeSort(right, errorCode);
    if (isAnError(errorCode, left, right)) {
        return NULL;
    }

    List* ListToReturn = merge(left, right, errorCode);
    if (isAnError(errorCode, left, right)) {
        return NULL;
    }

    deleteList(left, errorCode);
    deleteList(right, errorCode);
    return ListToReturn;
}
