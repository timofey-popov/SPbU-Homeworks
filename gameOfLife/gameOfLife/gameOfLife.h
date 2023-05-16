#pragma once

// Инициализация игрового поля.
// На вход принимает сетку, число строк и столбцов.
// Инициализирует каждый элемент сетки нулем или единицей случайныйм образом.
void initialize(int** grid, int rows, int columns);

// Распечатать сетку на экран.
void printGrid(int** grid, int rows, int columns);

// Посчитать количество живых соседей у клетки.
int countNeighbors(int** grid, int rows, int columns, int row, int column);

// Провести одну итерацию.
void playStep(int** grid, int rows, int columns);
