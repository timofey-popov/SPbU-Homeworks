#pragma once

// Все фунции в случае ошибок меняют переменную errorCode с 0 на 1.

// Структура для единицы стека.
// Содержит два поля: значение и указатель на предыдущую единицу стека.
typedef struct Unit {
    int value;
    struct Unit* previous;
} Unit;

