#include "gameOfLife.h"
#include <stdlib.h>

void initialize(int** grid, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid(int** grid, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int** grid, int rows, int columns, int row, int column) {
    int count = 0;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = column - 1; j <= column + 1; j++) {
            if (i >= 0 && i < rows && j >= 0 && j < columns && !(i == row && j == column)) {
                count += grid[i][j];
            }
        }
    }

    return count;
}

void playStep(int** grid, int rows, int columns) {
    int** newGrid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        newGrid[i] = (int*)malloc(columns * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int neighbors = countNeighbors(grid, rows, columns, i, j);
            if (grid[i][j]) {
                if (neighbors == 2 || neighbors == 3) {
                    newGrid[i][j] = 1;
                }
                else {
                    newGrid[i][j] = 0;
                }
            }
            else {
                if (neighbors == 3) {
                    newGrid[i][j] = 1;
                }
                else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        free(newGrid[i]);
    }
    free(newGrid);
}
