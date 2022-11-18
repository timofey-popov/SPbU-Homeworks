#pragma once

// ������� ��� ������ ������� �� �����.
// ��������� ��������� �� ������, ������ ������� � ���������� ��������� � ����� ������ ������.
void arrayPrint(int* arrayToPrint, int printingArraySize, int numberOfElementsInOneString);

// ���������� ���������.
// �� ���� ��������� ��������� �� ����������� ������ � ��� ������.
// ���������� -1, ���� �� ������� ��������� ������ ��� ��������������� ������, � 0, ���� �� ������.
int countingSort(int* arrayToSort, int arraySize);

// ������� ��� ��������� ���������������� ������� � ��������.
// �� ���� ��������� ��������� �� ��� ��� ������� � �� ������.
// � ����� ����� �� �������������� ��������� ������� � ���������� ��.
// ���������� true, ���� ������� ���������, � false � ��������� ������.
bool comparisonForTest(int* arrayForTest, int* referenceArray, size_t arraySize);

//������� � �������.
//���������� true � ������, ���� �� �������� ��������� � false � ��������� ������.
bool testCountingSort(int* numberOfFailedTest);
