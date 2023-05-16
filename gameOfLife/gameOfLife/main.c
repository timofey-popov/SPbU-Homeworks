#include "gameOfLife.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int getInteger() {
    int buffer = 0;

    int check = scanf_s("%d", &buffer);
    while (!check) {
        scanf_s("%*[^\n]");
        printf("Некорректный ввод. Попробуйте ещё раз: ");
        check = scanf_s("%d", &buffer);
    }

    return buffer;
}

int main() {
    setlocale(LC_ALL, "");

    printf("Введите количество строк: ");
    int rows = getInteger();

    printf("Введите количество столбцов: ");
    int columns = getInteger();

    printf("Введите количество итераций: ");
    int iterations = getInteger();

    // Выделение памяти для игрового поля
    int** grid = (int**)malloc(rows * sizeof(int*));
    if (grid == NULL) {
        printf("Memory allocation error.\n");
        return -1;
    }

    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(columns * sizeof(int));
        if (grid[i] == NULL) {
            printf("Memory allocation error.\n");
            return -1;
        }
    }

    // Инициализация игрового поля
    initialize(grid, rows, columns);

    // Выполнение заданного количества итераций игры
    for (int step = 0; step < iterations; step++) {
        printf("Шаг %d:\n", step + 1);
        printGrid(grid, rows, columns);
        playStep(grid, rows, columns);
    }

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
