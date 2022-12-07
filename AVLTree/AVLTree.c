#include "AVLTree.h"

#include <stdlib.h>
#include <stdbool.h>

struct AVLTree {
    struct Vertex* root;
};

typedef struct Vertex {
    Value value;
    struct Vertex* leftChild;
    struct Vertex* rightChild;

    short balance;
} Vertex;

AVLTree* createTree(ErrorCodes* errorCode) {
    AVLTree* newTree = calloc(1, sizeof(AVLTree));
    if (newTree == NULL) {
        *errorCode = memoryAllocationError;
        return NULL;
    }

    return newTree;
}

// Создать новый узел. Баланс и сыновья будут 0, значение - то, которое передали.
// Возвращает указатель на новый узел.
Vertex* createVertex(Value value, ErrorCodes* errorCode) {
    Vertex* newVertex = calloc(1, sizeof(Vertex));
    if (newVertex == NULL) {
        *errorCode = memoryAllocationError;
        return NULL;
    }

    newVertex->value = value;
    return newVertex;
}

// Основная функция вставки (рекурсивная). Не указана в .h, предназначена для внутренней работы.
// Работает с узлами, а не с деревом.
void insert(Value value, Vertex* vertex, ErrorCodes* errorCode) {
    if (vertex == NULL) {
        vertex = createVertex(value, errorCode);
        return;
    }

    if (value >= vertex->value) {
        vertex->balance += 1;

        if (vertex->rightChild == NULL) {
            vertex->rightChild = createVertex(value, errorCode);
            return;
        }

        insert(value, vertex->rightChild, errorCode);
        return;
    }

    vertex->balance -= 1;

    if (vertex->leftChild == NULL) {
        vertex->leftChild = createVertex(value, errorCode);
        return;
    }

    insert(value, vertex->leftChild, errorCode);
    return;
}

// Функция-обёртка. На самом деле просто передаёт ссылку на узел-корень дерева и управление функции insert.
// Работает с деревом.
void insertToTree(Value value, AVLTree* tree, ErrorCodes* errorCode) {
    if (tree == NULL) {
        *errorCode = nullPointerReceived;
        return;
    }

    insert(value, tree->root, errorCode);
}

void delete(Value value, Vertex* vertex, ErrorCodes* errorCode) {
    if (vertex == NULL) {
        return;
    }

    if 
}

void deleteFromTree(Value value, AVLTree* tree, ErrorCodes* errorCode) {
    if (tree == NULL) {
        *errorCode = nullPointerReceived;
        return;
    }

    delete(value, tree->root, errorCode);
}




Vertex* search(Value value, AVLTree* tree, ErrorCodes* errorCode) {

}

int main(void) {


    return 0;
}