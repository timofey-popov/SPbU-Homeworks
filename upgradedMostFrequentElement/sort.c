#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ������� ���������� ������� (����� ����� ����� ������) � �����.
int countRecords(FILE* file) {
    int counter = 0;

    while (fscanf_s(file, "%*d") != EOF) {
        counter += 1;
    }

    rewind(file);
    return counter;
}

// ������ ������ �� �����.
// �� ���� ��������� ��������� �� ����, ��������� �� ������ � ���������� ������� � �����.
void fileReading(FILE* file, int* arrayForNumbers, int numberOfRecords) {
    for (int i = 0; i < numberOfRecords; ++i) {
        fscanf_s(file, "%d", &arrayForNumbers[i]);
    }

    rewind(file);
}

// ������������ ����������� ��������� ������� � ������ ����������.
void returnArray(int* arrayFrom, int* arrayTo, int arraysSize) {
    for (int i = 0; i < arraysSize; ++i) {
        arrayTo[i] = arrayFrom[i];
    }
}

// ������� ���������� ������� �� ��� �����.
// ����� �������� ������� ���� ������ ���������� �������� �������, ������ - ������� ����������.
// � ����� ���������� �������� ��������� ������� (�����������) ����� ����� ����� ������� �������.
// ���������� ������ ����� ��������-�����������.
// ��������� �� 0 �� n - 1;
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
// ��������� �� 0 �� n - 1;
void quickSortExecution(int* arrayToSort, int leftElementNumber, int rightElementNumber) {

    if ((rightElementNumber - leftElementNumber + 1) < 10) {
        for (int i = leftElementNumber + 1; i <= rightElementNumber; ++i) {
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
        quickSortExecution(arrayToSort, leftElementNumber, separator - 1);
        quickSortExecution(arrayToSort, separator + 1, rightElementNumber);
    }
}

int quickSort(FILE* file, int* arrayForResult) {
    int numberOfRecords = countRecords(file);
    if (numberOfRecords == 0) {
        return 0;
    }

    int* arrayToSort = calloc(numberOfRecords, sizeof(int));
    if (arrayToSort == NULL) {
        return -1;
    }

    fileReading(file, arrayToSort, numberOfRecords);

    quickSortExecution(arrayToSort, 0, numberOfRecords - 1);

    returnArray(arrayToSort, arrayForResult, numberOfRecords);

    free(arrayToSort);

    return 0;
}