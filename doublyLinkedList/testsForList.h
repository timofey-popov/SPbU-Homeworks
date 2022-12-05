#pragma once

#include "doublyLinkedList.h"

#include <stdbool.h>

// ���� ��� create- � deleteList.
// ���������� true, ���� �� ������, � false � ��������� ������.
bool testForCreateAndDeleteList(void);

// ���� ��� ��������� ������� ��� � ���, � ������:
// pushToHead, pushToTail, popFromHead, popFromTail.
bool testForPushesAndPops(void);

// ���� ��� ���������� �������, � ������:
// insertNthElement, popNthElement, getNthValue, isEmpty, clearList.
bool testForRemainingFunctions(void);