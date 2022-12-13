#pragma once

#include <stdbool.h>

// ���� ������:
// 0 - ��� ������.
// 1 - ������ ��������� ������.
// 2 - � �������� ��������� �� ������� ������� NULL.
// 3 - � ������� ��� ���������.
typedef enum ErrorCodes {
    noErrors,
    memoryAllocationError,
    nullPointerReceived,
    noElemensInQueue
} ErrorCodes;

// ��� ������ ��� �������� � �������.
// ���� ����� �������� - ������ ��� ������ � ���� �����.
typedef int Value;

// ����������� ��� ������ "�������".
typedef struct Queue Queue;

// ������ ������ �������.
// �� ���� ��������� ��������� �� ���������� � ����� ������.
// ���������� ��������� �� �������, ���� �� ������ ���������, � ��������� ������ ���������� NULL.
// � ������ ������ ������� �� ��������, ������� � �� �����.
Queue* createQueue(ErrorCodes* errorCode);

// ��������� ������� � ����� �������.
// �� ���� ��������� ����������� ��������, ��������� �� ������� � ��������� �� ���������� � ����� ������.
void enqueue(Value value, Queue* queue, ErrorCodes* errorCode);

// ������� ������� �� ������ ������� � ���������� ��������, ������� � �� ������.
// �� ���� ��������� ��������� �� ������� � ��������� �� ���������� � ����� ������.
Value dequeue(Queue* queue, ErrorCodes* errorCode);

// ������� ��� �������� �� �������, ������ �� �� ��������.
// �� ���� ��������� ��������� �� ������� � ��������� �� ���������� � ����� ������.
void clear(Queue* queue, ErrorCodes* errorCode);

// ���������� true, ���� ������� �����, � false � ��������� ������.
// ���� � �������� ��������� �� ������� ������� NULL, ���������� false � ������ ��� ������.
bool isEmpty(Queue* queue, ErrorCodes* errorCode);

// ������� ��������� �������.
void deleteQueue(Queue* queue, ErrorCodes* errorCode);
