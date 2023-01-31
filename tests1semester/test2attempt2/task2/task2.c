#include "task2.h"

#include <stdlib.h>

// Структура для элемента множества.
struct Set {
    Value data;
    Set* head;
    Set* next;
    Set* tail;
};

Set* createSet(Value value, ErrorCodesForSet* errorCode) {
    Set* newSet = calloc(1, sizeof(Set));
    if (newSet == NULL) {
        *errorCode = memoryAllocationError;
        return NULL;
    }

    newSet->data = value;
    newSet->head = newSet;
    newSet->tail = newSet;

    return newSet;
}

Set* unite(Set* set1, Set* set2, ErrorCodesForSet* errorCode) {
    if (set1 == NULL || set2 == NULL) {
        *errorCode = gotNullPointer;
        return NULL;
    }

    Set* head1 = set1->head;
    Set* head2 = set2->head;

    if (head1 == head2) {
        return head1;
    }

    head1->tail->next = head2;
    head1->tail = head2->tail;

    while (head2) {
        head2->head = head1;
        head2 = head2->next;
    }

    return head1;
}

bool isTheSameSet(Set* set1, Set* set2, ErrorCodesForSet* errorCode) {
    if (set1 == NULL || set2 == NULL) {
        *errorCode = gotNullPointer;
        return false;
    }

    return set1->head == set2->head;
}

void freeSet(Set* set, ErrorCodesForSet* errorCode) {
    if (set == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    Set* setToDelete = set->head;
    Set* temporaryNext = setToDelete->next;

    while (temporaryNext) {
        free(setToDelete);
        setToDelete = temporaryNext;
        temporaryNext = setToDelete->next;
    }

    free(setToDelete);
}