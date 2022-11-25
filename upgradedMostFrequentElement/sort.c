#include "sort.h"

#include <stdbool.h>

// ������� ���������� ������� �� ��� �����.
// ����� �������� ������� ���� ������ ���������� �������� �������, ������ - ������� ����������.
// � ����� ���������� �������� ��������� ������� (�����������) ����� ����� ����� ������� �������.
// ���������� ������ ����� ��������-�����������.
int partition(int* arrayToSort, int leftElementNumber, int rightElementNumber) {
    int pivot = arrayToSort[rightElementNumber];

    int i = leftElementNumber;
    for (int j = leftElementNumber; j < rightElementNumber; ++j) {
        if (arrayToSort[j] <= pivot) {
            int temporary = arrayToSort[i];
            arrayToSort[i] = arrayToSort[j];
            arrayToSort[j] = temporary;

            ++i;
        }
    }

    int temporary = arrayToSort[i];
    arrayToSort[i] = arrayToSort[rightElementNumber];
    arrayToSort[rightElementNumber] = temporary;

    return i;
}

// ����������� ������� ������� ����������.
// �������� ���� �� ������ �� �������, ������������� �������� ����������, - 1, � �� ������� + 1 �� ����� �������.
// ��� ������� � ��������, ������������ �������� ����������, ��������� �� �����.
// ���� ��������� � ������� ������ 10, ������� ��������� �� �������� ���������.
void quickSort(int* arrayToSort, int leftElementNumber, int rightElementNumber) {
    if ((rightElementNumber - leftElementNumber + 1) < 10) {
        for (int i = leftElementNumber + 1; i < rightElementNumber + 1; ++i) {
            int k = i;
            while (k > leftElementNumber && arrayToSort[k] < arrayToSort[k - 1]) {
                int temporary = arrayToSort[k];
                arrayToSort[k] = arrayToSort[k - 1];
                arrayToSort[k - 1] = temporary;

                k--;
            }
        }
    }

    else if (leftElementNumber < rightElementNumber) {
        int separator = partition(arrayToSort, leftElementNumber, rightElementNumber);
        quickSort(arrayToSort, leftElementNumber, separator - 1);
        quickSort(arrayToSort, separator + 1, rightElementNumber);
    }
}