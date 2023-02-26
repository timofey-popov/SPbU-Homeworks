#pragma once

typedef enum ErrorCodes {
    noErrors,
    gotNullPointer,
    memoryError
} ErrorCodes;

typedef struct List List;

List* createList(ErrorCodes* errorCode);

void addElement(List* list, char* value, ErrorCodes* errorCode);

void deleteList(List* list, ErrorCodes* errorCode);

void addAStrings(List* list, ErrorCodes* errorCode);
