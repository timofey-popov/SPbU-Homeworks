#include "customStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Структура для единицы стека.
// Содержит два поля: значение и указатель на предыдущую единицу стека.
typedef struct Unit {
    int value;
    struct Unit* previous;
} Unit;

void push(int value, Unit** head, int* errorCode) {
    Unit* newHead = malloc(sizeof(Unit));

    if (newHead == NULL) {
        *errorCode = 1;
        printf("Memory allocation problem\n");
        return;
    }

    newHead->previous = *head;
    newHead->value = value;

    *head = newHead;
}

int pop(Unit** head, int* errorCode) {
    if (*head == NULL) {
        *errorCode = 1;
        printf("Null element pop attempt\n");
        return -1;
    }

    int valueToReturn = (*head)->value;
    Unit* temporaryAddress = (*head)->previous;

    free(*head);
    *head = temporaryAddress;

    return valueToReturn;
}

void clear(Unit** head) {
    while (*head != NULL) {
        pop(head, NULL);
    }
}

bool isEmpty(Unit** head) {
    return *head == NULL;
}

void printStack(Unit** head) {
    Unit* headCopy = *head;

    if (headCopy == NULL) {
        printf("There are no elements in stack\n\n");
        return;
    }

    while (headCopy != NULL) {
        printf("%d ", headCopy->value);
        headCopy = headCopy->previous;
    }
    printf("\n\n");
}

int main(void)
{
    int errorCode = 0;
    Unit* head = NULL;

    printf("%d\n\n", isEmpty(&head));

    printStack(&head);

    push(10, &head, &errorCode);

    printStack(&head);

    printf("%d\n\n", isEmpty(&head));

    return 0;
}