#pragma once

#include <stdbool.h>

// ���� ������:
// 0 - ��� ������.
// 1 - ������ ��������� ������ ��� ����� ������� (createQueue).
// 2 - � �������� ��������� �� ������� ������� NULL (enqueue).
// 3 - ������ ��������� ������ ��� ����� ������� ������� (enqueue).
// 4 - � �������� ��������� �� ������� ������� NULL (dequeue).
// 5 - � ������� ��� ���������� ��� dequeue (dequeue).
// 6 - � �������� ��������� �� ������� ������� NULL (clear).
// 7 - � �������� ��������� �� ������� ������� NULL (isEmpty).
// 8 - � �������� ��������� �� ������� ������� NULL (deleteQueue).
typedef enum ErrorCodes {
    noErrors,
    createQueueMemoryError,
    enqueueGotNullPointer,
    enqueueMemoryError,
    dequeueGotNullPointer,
    dequeueQueueHasNoElemens,
    clearGotNullPointer,
    isEmptyGotNullPointer,
    deleteQueueGotNullPointer
} ErrorCodes;

// ��� ������ ��� �������� � �������.
// ���� ����� �������� - ������ ��� ������ � ���� �����.
typedef int Value;

// ����������� ��� ������ "�������".
typedef struct Queue Queue;

// ������ ������ �������.
// �� ���� ��������� ��������� �� ���������� � ����� ������.
// ���������� ��������� �� �������, ���� �� ������ ���������, � ��������� ������ ���������� NULL � ������ ��� ������.
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
