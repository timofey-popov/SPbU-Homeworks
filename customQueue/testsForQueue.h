#pragma once

#include "customQueue.h"

// Тест создания и удаления очереди.
// True - тест успешно пройден, false в обратном случае.
bool testForCreateAndDeleteQueue(void);

// Тест добавления элемента в очередь и удаления элемента из очереди.
// True - тест успешно пройден, false в обратном случае.
bool testForEnqueueAndDequeue(void);

// Тест функций очистки очереди и проверки её на пустоту.
// True - тест успешно пройден, false в обратном случае.
bool testForClearAndIsEmpty(void);
