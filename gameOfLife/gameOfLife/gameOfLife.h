#pragma once

// ������������� �������� ����.
// �� ���� ��������� �����, ����� ����� � ��������.
// �������������� ������ ������� ����� ����� ��� �������� ���������� �������.
void initialize(int** grid, int rows, int columns);

// ����������� ����� �� �����.
void printGrid(int** grid, int rows, int columns);

// ��������� ���������� ����� ������� � ������.
int countNeighbors(int** grid, int rows, int columns, int row, int column);

// �������� ���� ��������.
void playStep(int** grid, int rows, int columns);
