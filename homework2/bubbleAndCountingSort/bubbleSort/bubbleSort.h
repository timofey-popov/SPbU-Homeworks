#pragma once

// ������� ��� ������ ������� �� �����.
// ��������� ��������� �� ������, ������ ������� � ���������� ��������� � ����� ������ ������.
void arrayPrint(int* arrayToPrint, int printingArraySize, int numberOfElementsInOneString);

// ���������� ���������.
// �� ���� ��������� ��������� �� ����������� ������ � ��� ������.
void bubbleSort(int* arrayToSort, int arraySize);

// ������� ��� ��������� ���������������� ������� � ��������.
// �� ���� ��������� ��������� �� ��� ��� ������� � �� ������.
// � ����� ����� �� �������������� ��������� ������� � ���������� ��.
// ���������� true, ���� ������� ���������, � false � ��������� ������.
bool comparisonForTest(int* arrayForTest, int* referenceArray, size_t arraySize);

//������� � �������.
//���������� true � ������, ���� �� �������� ��������� � false � ��������� ������.
bool testBubbleSort(int* numberOfFailedTest);
