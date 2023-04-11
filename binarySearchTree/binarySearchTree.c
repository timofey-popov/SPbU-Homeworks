#include "binarySearchTree.h"

#include <stdlib.h>

// Структура для элементов словаря.
typedef struct DictionaryElement {
    int key;
    Value value;
    DictionaryElement* leftChild;
    DictionaryElement* rightChild;
} DictionaryElement;

// Реализация АТД "Словарь".
struct Dictionary {
    DictionaryElement* root;
};

Dictionary* createDictionary(ErrorCodes* errorCode) {
    Dictionary* newDictionary = malloc(sizeof(Dictionary));
    if (newDictionary == NULL) {
        *errorCode = memoryAllocationError;
    }

    return newDictionary;
}

void deleteDictionary(Dictionary* dictionaryToRemove, ErrorCodes* errorCode) {

}
