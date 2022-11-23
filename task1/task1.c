#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tests.h"


// Структура для двусвязного списка.
typedef struct Unit {
    int value;
    struct Unit* next;
    struct Unit* prev;
} Unit;

// Функция, добавляющая элемент в конец списка.
// Возвращает 0, если всё прошло успешно и 1 в противном случае.
int push(int value, Unit** head, Unit** tail) {
    Unit* newElement = malloc(sizeof(Unit));
    if (newElement == NULL) {
        printf("Memory allocation problem\n");
        return 1;
    }

    if (*tail == NULL) {
        *head = newElement;
        *tail = newElement;
        newElement->prev = NULL;
    } else {
        (*tail)->next = newElement;
        newElement->prev = *tail;
    }

    newElement->value = value;
    newElement->next = NULL;

    *tail = newElement;
    return 0;
}

// Функция, полностью очищающая список.
int clear(Unit** tail) {
    if (*tail == NULL) {
        printf("Empty list clear attempt\n");
        return 1;
    }

    while (true) {
        Unit* temporary = *tail;
        (*tail) = (*tail)->prev;
        free(temporary);
        if (*tail == NULL) {
            return 0;
        }
    }
}

// Функция, заполняющая список значениями из файла.
int fill(FILE* file, Unit** head, Unit** tail) {
    int value = 0;
    int correctnessCheck = fscanf(file, "%d", &value);

    while (correctnessCheck != EOF) {
        push(value, head, tail);
        correctnessCheck = fscanf(file, "%d", &value);
    }

    fclose(file);
    return 0;
}

// Функция проверки на симметричность.
bool isSymmetrical(Unit** head, Unit** tail, int* errorCode) {
    if (*head == NULL) {
        printf("List is empty\n");
        *errorCode = 1;
        return false;
    }

    if (*head == *tail) {
        return true;
    }

    Unit* left = *head;
    Unit* right = *tail;

    while (left != right) {
        if (left->value != right->value) {
            return false;
        }

        left = left->next;
        right = right->prev;
    }

    return true;
}

int main(void) {
    if (!testForPushAndClear() || !testForFill() || !testForIsSymmetrical()) {
        printf("Tests failed.\n");
        return -1;
    } else {
        printf("*tests passed*\n");
        printf("------------------\n\n");
    }

    int errorCode = 0;

    Unit* head = NULL;
    Unit* tail = NULL;

    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Cannot open the file\n");
        return -1;
    }

    errorCode = fill(file, &head, &tail);
    if (errorCode) {
        printf("Unable to fill\n");
        return -1;
    }

    bool result = isSymmetrical(&head, &tail, &errorCode);
    if (errorCode) {
        printf("Something wrong with isSymmetrical\n");
        return -1;
    }

    if (result) {
        printf("This list is symmetrical\n");
    } else {
        printf("This list is not symmetrical\n");
    }

    clear(&tail);

    return 0;
}
