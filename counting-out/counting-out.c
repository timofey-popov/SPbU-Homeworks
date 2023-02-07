#include "counting-out.h"

#include <stdlib.h>

// Локальные коды ошибок. Переводятся в глобальные основной функцией (подсчёта).
typedef enum ListErrors {
    noErrorsInList,
    noMemoryAllocation,
    gotNullPointer
} ListErrors;

// Элемент циклического списка.
// "Next" для последнего элемента - это голова списка.
typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

// "Циклический список".
// Представляет из себя указатели на голову и хвост списка. 
typedef struct CircularList {
    ListElement* head;
    ListElement* tail;
} CircularList;

// Создать новый список. Если код ошибки не ноль - список не был создан.
CircularList* createList(ListErrors* errorCode) {
    CircularList* newList = calloc(1, sizeof(CircularList));
    if (newList == NULL) {
        *errorCode = noMemoryAllocation;
        return NULL;
    }

    return newList;
}

// Добавить значиение в список.
void addToList(int value, CircularList* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    // Создание нового элемента списка.
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL) {
        *errorCode = noMemoryAllocation;
        return;
    }
    newElement->value = value;

    // Если добавляем в пустой список:
    if (list->head == NULL) {
        list->head = newElement;
        list->tail = newElement;
        newElement->next = newElement;
        return;
    }

    // В остальных случаях:
    list->tail->next = newElement;
    list->tail = newElement;
    newElement->next = list->head;
}

// Удалить значение из списка.
// Будет удалено первое значение, совпадающее с заданным.
// Если такого значения нет - ничего не будет удалено, ошибки не возникнет.
void deleteFromList(int value, CircularList* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    // Пустой список - значит, нечего удалять.
    if (list->head == NULL) {
        return;
    }

    // Начинаем поиск.
    ListElement* previousElement = list->tail;
    ListElement* temporaryPointer = list->head;

    while ((temporaryPointer->value != value) && (temporaryPointer != list->tail)) {
        previousElement = temporaryPointer;
        temporaryPointer = temporaryPointer->next;
    }

    // Если нашли совпадение:
    if (temporaryPointer->value == value) {
        previousElement->next = temporaryPointer->next;
        // Если удаляем голову:
        if (temporaryPointer == list->head) {
            list->head = list->head->next;
        }

        // Если удаляем хвост:
        if (temporaryPointer == list->tail) {
            list->tail = previousElement;
        }

        // Если в списке всего один элемент:
        if (temporaryPointer == previousElement) {
            list->head = NULL;
            list->tail = NULL;
        }

        free(temporaryPointer);
    }
}

// Удалить список.
void deleteList(CircularList* list, ListErrors* errorCode) {
    if (list == NULL) {
        *errorCode = gotNullPointer;
        return;
    }

    while (list->head != NULL) {
        deleteFromList(list->head->value, list, errorCode);
    }

    free(list);
}

// Основная функция. Описана в заголовке.
int calculateSuitablePosition(int n, int m, CountingOutErrors* errorCode) {
    // Локально создаём список:
    ListErrors localErrorCode = noErrorsInList;
    CircularList* list = createList(&localErrorCode);
    if (localErrorCode || (list == NULL)) {
        *errorCode = memoryAllocationError;
        return -1;
    }

    // Набиваем в список n номеров воинов по порядку:
    for (int i = 1; i <= n; ++i) {
        addToList(i, list, &localErrorCode);
        if (localErrorCode) {
            if (localErrorCode == noMemoryAllocation) {
                *errorCode = memoryAllocationError;
            }
            else {
                *errorCode = programDoesNotWork;
            }
            deleteList(list, &localErrorCode);
            return -1;
        }
    }

    ListElement* pointer = list->tail;
    ListElement* nextMove = list->head;

    // Остановимся, когда в списке останется только один элемент.
    while (list->head != list->tail) {
        pointer = nextMove;

        // Делаем m - 1 шаг, т. к. один шаг уже сделали, когда перешли на nextMove.
        for (int i = 0; i < m - 1; ++i) {
            pointer = pointer->next;
        }

        // Запоминаем следующий шаг и удаляем ту позицию, куда показывает указатель:
        nextMove = pointer->next;
        deleteFromList(pointer->value, list, &localErrorCode);
        if (localErrorCode) {
            *errorCode = programDoesNotWork;
            deleteList(list, &localErrorCode);
            return -1;
        }
    }
    
    // Сохраняем значение, удаляем список, возвращаем значение (даже если список не удалился).
    int valueToReturn = nextMove->value;

    deleteList(list, &localErrorCode);
    if (localErrorCode) {
        *errorCode = programDoesNotWork;
    }

    return valueToReturn;
}

// Тест для функций создания и удаления списка.
bool testForCreateAndDeleteList(void) {
    ListErrors testErrorCode = noErrorsInList;

    CircularList* testList = createList(&testErrorCode);
    if (testErrorCode || (testList == NULL)) {
        return false;
    }

    deleteList(testList, &testErrorCode);

    return !testErrorCode;
}

// Тест для разных сценариев добавления и удаления элементов из списка.
bool testForAddAndDeleteValue(void) {
    ListErrors testErrorCode = noErrorsInList;

    CircularList* testList = createList(&testErrorCode);
    if (testErrorCode || (testList == NULL)) {
        return false;
    }

    deleteFromList(100, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(1, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(50, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(1, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(-6, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(15, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(3, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(15, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    addToList(20, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(-6, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteFromList(20, testList, &testErrorCode);
    if (testErrorCode) {
        deleteList(testList, &testErrorCode);
        return false;
    }

    deleteList(testList, &testErrorCode);

    return !testErrorCode;
}

// Функция-обёртка, запускает два теста выше.
bool insideTests(void) {
    return testForCreateAndDeleteList() && testForAddAndDeleteValue();
}