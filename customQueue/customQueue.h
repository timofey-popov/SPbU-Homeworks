#pragma once

#include <stdbool.h>

// Структура, являющаяся базовым элементом очереди.
// Хранит целое число и ссылку на следующий элемент в очереди
typedef struct Unit
{
    int value;
    struct Unit* next;
} Unit;

// Функция для добавления элемента в конец очереди.
void enqueue(int value, Unit** head, Unit** tail, int* errorCode);

// Функция для удаления элемента из начала очереди.
int dequeue(Unit** head, Unit** tail, int* errorCode);

// Функция для очистки очереди. Удаляет все элементы.
void clear(Unit** head, Unit** tail, int* errorCode);

// Функция-проверка очереди на пустоту.
// Возвращает true, если очередь пуста, и false в обратном случае.
bool isEmpty(Unit** head);