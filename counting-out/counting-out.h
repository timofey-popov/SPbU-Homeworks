#pragma once

#include <stdbool.h>

// Коды ошибок.
typedef enum CountingOutErrors {
    noErrors,
    memoryAllocationError,
    programDoesNotWork
} CountingOutErrors;

// Функция, тестирующая работоспособность второстепенных функций программы. Если при запуске возвращает false - программа работает некорректно.
// Рекомендуется запускать перед началом работы.
bool insideTests(void);

// Возвращает номер k позиции последнего живого воина, если воинов n и убивают каждого m-того.
int calculateSuitablePosition(int n, int m, CountingOutErrors* errorCode);
