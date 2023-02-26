#pragma once

// ���� ������:
// 1 - ������ ��� ��������� ������ ��� ������ ������ (createDoublyLinkedList).
// 2 - ������ ��� ��������� ������ ��� ������ �������� ������ (pushToTail).
// 3 - � clear ������� ������ ������ (clear).
// 4 - � fill � �������� ������ ������� ��������� �� NULL (fill).
// 5 - � isSymmetrical ������� ������ ������ (isSymmetrical).
// 6 - � deleteList � �������� ������ ������� ��������� �� NULL (deleteList).


// ��� "���������� ������".
typedef struct DoublyLinkedList DoublyLinkedList;

// ������� ���������� ������.
// �� ���� ��������� ��������� �� ��� ������, ���������� ��������� �� ��������� ������.
DoublyLinkedList* createDoublyLinkedList(int* errorCode);

// �������� ������� � ����� ������.
// ���������� 0, ���� �� ������ ������� � 1 � ��������� ������.
void pushToTail(int value, DoublyLinkedList* list, int* errorCode);

// �������, ��������� ��������� ������.
void clear(DoublyLinkedList* list, int* errorCode);

// �������, ����������� ������ � ������ ���������� �� ����� � ������� ������� push.
void fill(FILE* file, DoublyLinkedList* list, int* errorCode);

// ������� �������� ������ �� ��������������.
bool isSymmetrical(DoublyLinkedList* list, int* errorCode);

// ������� �������� ������.
void deleteList(DoublyLinkedList* list, int* errorCode);
