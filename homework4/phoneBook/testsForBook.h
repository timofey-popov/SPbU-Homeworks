#pragma once

#include "phoneBook.h"

// Тест для функций начального чтения файла и поиска.
bool testForInitialReadingAndSearch(void);

// Тест для функции записи в файл.
// Сначала записывает заданную структуру в файл, затем читает этот же файл в другую структуру
// и сравнивает структуры поэлементно.
bool testForRecordToFile(void);
