#pragma once

// Структура для двусвязного списка.
typedef struct Unit {
    int value;
    struct Unit* next;
    struct Unit* prev;
} Unit;

// Функция, добавляющая элемент в конец списка.
// Возвращает 0, если всё прошло успешно и 1 в противном случае.
int push(int value, Unit** head, Unit** tail);

// Функция, полностью очищающая список.
int clear(Unit** tail);

// Функция, заполняющая список значениями из файла.
int fill(FILE* file, Unit** head, Unit** tail);

// Функция проверки на симметричность.
bool isSymmetrical(Unit** head, Unit** tail, int* errorCode);
