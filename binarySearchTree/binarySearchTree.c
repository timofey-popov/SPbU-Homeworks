#include "binarySearchTree.h"

#include <stdlib.h>

// Структура для элементов словаря.
typedef struct DictionaryElement {
    int key;
    Value value;
    struct DictionaryElement* leftChild;
    struct DictionaryElement* rightChild;
} DictionaryElement;

// Реализация АТД "Словарь".
typedef struct Dictionary {
    DictionaryElement* root;
} Dictionary;

// Служебная функция. Находит элемент с указанным ключом и его родителя.
// Возвращает указатель на родителя или NULL, если такого ключа нет.
// Сам элемент возвращает в специальную переменную для этого.
// Предполагает, что словарь не NULL.
DictionaryElement* getElementWithGivenKeyAndItsParent(int key, Dictionary* dictionary, DictionaryElement* variableForElementItself) {
    DictionaryElement* previousElement = NULL;
    DictionaryElement* currentElement = dictionary->root;

    while (currentElement != NULL) {
        if (currentElement->key == key) {
            variableForElementItself = previousElement;
            return currentElement;
        }

        previousElement = currentElement;

        if (key > currentElement->key) {
            currentElement = currentElement->rightChild;
        }
        else {
            currentElement = currentElement->leftChild;
        }
    }

    variableForElementItself = NULL;
    return NULL;
}

// Служебная функция. Находит элемент с указанным ключом.
// Возвращает указатель на него или NULL, если такого ключа нет.
// Предполагает, что словарь не NULL.
DictionaryElement* getElementWithGivenKey(int key, Dictionary* dictionary) {
    DictionaryElement* desiredElement = NULL;
    getElementWithGivenKeyAndItsParent(key, dictionary, desiredElement);

    return desiredElement;
}

// Служебная функция.
// Удалить всё поддерево, начиная с данного элемента и включая его.
void deleteSubtree(DictionaryElement* element) {
    if (element == NULL) {
        return;
    }

    deleteSubtree(element->leftChild);
    deleteSubtree(element->rightChild);
    free(element);
}

Dictionary* createDictionary(ErrorCodes* errorCode) {
    Dictionary* newDictionary = calloc(1, sizeof(Dictionary));
    if (newDictionary == NULL) {
        *errorCode = memoryAllocationError;
    }

    return newDictionary;
}

void addValue(Value value, int key, Dictionary* dictionary, ErrorCodes* errorCode) {
    if (dictionary == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    DictionaryElement* newElement = calloc(1, sizeof(DictionaryElement));
    if (newElement == NULL) {
        *errorCode = memoryAllocationError;
        return;
    }

    newElement->key = key;
    newElement->value = value;

    // Если до этого не было элементов:
    if (dictionary->root == NULL) {
        dictionary->root = newElement;
        return;
    }

    DictionaryElement* previousElement = NULL;
    DictionaryElement* currentElement = dictionary->root;

    while (currentElement != NULL) {
        if (currentElement->key == key) {
            currentElement->value = value;
            return;
        }
        else if (key > currentElement->key){
            previousElement = currentElement;
            currentElement = currentElement->rightChild;
        }
        else {
            previousElement = currentElement;
            currentElement = currentElement->leftChild;
        }
    }

    if (key > previousElement->key) {
        previousElement->rightChild = newElement;
    }
    else {
        previousElement->leftChild = newElement;
    }
}

Value getValueByKey(int key, Dictionary* dictionary, ErrorCodes* errorCode) {
    if (dictionary == NULL) {
        *errorCode = gotNullPointer;
        return NULL;
    }

    DictionaryElement* desiredElement = getElementWithGivenKey(key, dictionary);

    if (desiredElement == NULL) {
        return NULL;
    }
    else {
        return desiredElement->value;
    }
}

bool isSuchKey(int key, Dictionary* dictionary, ErrorCodes* errorCode) {
    if (dictionary == NULL) {
        *errorCode = gotNullPointer;
        return false;
    }

    DictionaryElement* desiredElement = getElementWithGivenKey(key, dictionary);

    return desiredElement != NULL;
}

void deleteKeyAndItsValue(int key, Dictionary* dictionary, ErrorCodes* errorCode) {
    if (dictionary == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    if (dictionary->root == NULL) {
        return;
    }

    DictionaryElement* elementToDelete = NULL;
    DictionaryElement * parent = getElementWithGivenKeyAndItsParent(key, dictionary, elementToDelete);
    if (elementToDelete == NULL) {
        return;
    }

    
    if (elementToDelete->leftChild == NULL) {
        if (elementToDelete->rightChild == NULL) {
            // Если это лист, то удаляем его из детей родителя и освобождаем память.

            if (key > parent->key) {
                parent->rightChild = NULL;
            }
            else {
                parent->leftChild = NULL;
            }

            free(elementToDelete);
        }
        else {
            // Если у удаляемого узла есть только правый ребёнок:
            DictionaryElement* elementForReplace = elementToDelete->rightChild;
            DictionaryElement* elementForReplacesParent = elementToDelete;

            // Ищем самый левый узел из правого поддерева и его родителя.
            while (elementForReplace->leftChild != NULL) {
                elementForReplacesParent = elementForReplace;
                elementForReplace = elementForReplace->leftChild;
            }

            // Цепляем правое поддерево самого левого узла к его родителю.
            elementForReplacesParent->leftChild = elementForReplace->rightChild;

            // Заменяем удаляемый элемент на самый левый в списке детей родителя удаляемого элемента.
            if (key > parent->key) {
                parent->rightChild = elementForReplace;
            }
            else {
                parent->leftChild = elementForReplace;
            }

            elementForReplace->rightChild = elementToDelete->rightChild;

            free(elementToDelete);
        }
    }
    else {
        // Если у удаляемого узла есть только левый ребёнок:
        DictionaryElement* elementForReplace = elementToDelete->leftChild;
        DictionaryElement* elementForReplacesParent = elementToDelete;

        // Ищем самый правый узел из левого поддерева и его родителя.
        while (elementForReplace->rightChild != NULL) {
            elementForReplacesParent = elementForReplace;
            elementForReplace = elementForReplace->rightChild;
        }

        // Цепляем левое поддерево самого правого узла к его родителю.
        elementForReplacesParent->rightChild = elementForReplace->leftChild;

        // Заменяем удаляемый элемент на самый правый в списке детей родителя удаляемого элемента.
        if (key > parent->key) {
            parent->rightChild = elementForReplace;
        }
        else {
            parent->leftChild = elementForReplace;
        }

        elementForReplace->leftChild = elementToDelete->leftChild;

        free(elementToDelete);
    }
}

void deleteDictionary(Dictionary* dictionaryToRemove) {
    if (dictionaryToRemove == NULL) {
        return;
    }

    deleteSubtree(dictionaryToRemove->root);
    free(dictionaryToRemove);
}
