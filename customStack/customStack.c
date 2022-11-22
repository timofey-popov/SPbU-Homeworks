#include "customStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Все фунции в случае ошибок меняют переменную errorCode с 0 на 1.

// Структура для единицы стека.
// Содержит два поля: значение и указатель на предыдущую единицу стека.
typedef struct Unit {
    int value;
    struct Unit* previous;
} Unit;

// Функция для добавления элемента стека.
// На вход принимает значение, которое нужно добавить, указатель на голову стека и указатель на переменную с кодом ошибки.
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

// Функция для удаления элемента из стека, которая возвращает значение этого элемента.
// На вход принимает указатель на голову стека и указатель на переменную с кодом ошибки.
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

// Функция полной очистки стека.
// На вход принимает указатель на голову стека.
void clear(Unit** head) {
    while (*head != NULL) {
        pop(head, NULL);
    }
}

// Функция проверки стека на пустоту.
// На вход принимает указатель на голову стека.
// Возвращает true, если стек пуст, и false в противном случае.
bool isEmpty(Unit** head) {
    return *head == NULL;
}

// Функция, печатающая стек на экран (никак не меняет стек).
// На вход принимает указатель на голову стека.
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