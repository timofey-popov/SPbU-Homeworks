#pragma once

#include <stdbool.h>

typedef struct PhonebookStruct PhonebookStruct;

void initialFileReading(FILE* file, PhonebookStruct* book, int* counterOfRecords);

bool search(PhonebookStruct* book, int counterOfRecords, int mode);

void recordToFile(PhonebookStruct* book, int counterOfRecords);
