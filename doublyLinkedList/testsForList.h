#pragma once

#include "doublyLinkedList.h"

#include <stdbool.h>

// Тест для create- и deleteList.
// Возвращает true, если всё хорошо, и false в противном случае.
bool testForCreateAndDeleteList(void);

// Тест для различных функций пуш и поп, а именно:
// pushToHead, pushToTail, popFromHead, popFromTail.
bool testForPushesAndPops(void);

// Тест для оставшихся функций, а именно:
// insertNthElement, popNthElement, getNthValue, isEmpty, clearList.
bool testForRemainingFunctions(void);