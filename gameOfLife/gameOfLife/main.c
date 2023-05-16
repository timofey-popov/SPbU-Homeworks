#include "gameOfLife.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int getInteger() {
    int buffer = 0;

    int check = scanf_s("%d", &buffer);
    while (!check) {
        scanf_s("%*[^\n]");
        printf("������������ ����. ���������� ��� ���: ");
        check = scanf_s("%d", &buffer);
    }

    return buffer;
}

int main() {
    setlocale(LC_ALL, "");

    printf("������� ���������� �����: ");
    int rows = getInteger();

    printf("������� ���������� ��������: ");
    int columns = getInteger();

    printf("������� ���������� ��������: ");
    int iterations = getInteger();

    // ��������� ������ ��� �������� ����
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

    // ������������� �������� ����
    initialize(grid, rows, columns);

    // ���������� ��������� ���������� �������� ����
    for (int step = 0; step < iterations; step++) {
        printf("��� %d:\n", step + 1);
        printGrid(grid, rows, columns);
        playStep(grid, rows, columns);
    }

    // ������������ ������
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
