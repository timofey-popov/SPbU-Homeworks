#pragma once

// Коды ошибок:
//
typedef enum ErrorCodes {
    noErrors,
};

typedef int Value;

typedef struct LinkedList LinkedList;

LinkedList* createLinkedList(ErrorCodes* errorCode);

int getFirstOrdinalWithSuchValue(Value value, LinkedList* list, ErrorCodes* errorCode);

void addToEnd(Value value, LinkedList* list, ErrorCodes* errorCode);

void addToBeginning(Value value, LinkedList* list, ErrorCodes* errorCode);

void addAfterValue(Value addedValue, Value previousValue, LinkedList* list, ErrorCodes* errorCode);

void addBeforeValue(Value addedValue, Value nextValue, LinkedList* list, ErrorCodes* errorCode);

void addAfterOrdinal(Value addedValue, Value previousOrdinal, LinkedList* list, ErrorCodes* errorCode);

void addBeforeOrdinal(Value addedValue, Value nextOrdinal, LinkedList* list, ErrorCodes* errorCode);