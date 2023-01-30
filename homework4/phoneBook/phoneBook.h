#pragma once

#include <stdbool.h>
#include <stdio.h>

// Структура для записей в телефонной книге.
typedef struct PhonebookStruct PhonebookStruct;

// Начальное чтение файла в массив структур.
void initialFileReading(FILE* file, PhonebookStruct* book, int* counterOfRecords);

// Найти запись в массиве структур.
bool search(PhonebookStruct* book, char* stringForCompare, int* arrayForMatches, int* numberOfMatches, int counterOfRecords, int mode);

// Записать массив структур в файл.
int recordToFile(PhonebookStruct* book, const char* fileName, int counterOfRecords);
