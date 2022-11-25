#pragma once

// Коды ошибок:
// 1 - ошибка при выделении памяти для нового списка (createDoublyLinkedList).
// 2 - ошибка при выделении памяти для нового элемента списка (pushToTail).
// 3 - в clear передан пустой список (clear).
// 4 - в fill в качестве списка передан указатель на NULL (fill).
// 5 - в isSymmetrical передан пустой список (isSymmetrical).
// 6 - в deleteList в качестве списка передан указатель на NULL (deleteList).


// АТД "двусвязный список".
typedef struct DoublyLinkedList DoublyLinkedList;

// Создать двусвязный список.
// На вход принимает указатель на код ошибки, возвращает указатель на созданный список.
DoublyLinkedList* createDoublyLinkedList(int* errorCode);

// Добавить элемент в конец списка.
// Возвращает 0, если всё прошло успешно и 1 в противном случае.
void pushToTail(int value, DoublyLinkedList* list, int* errorCode);

// Функция, полностью очищающая список.
void clear(DoublyLinkedList* list, int* errorCode);

// Функция, заполняющая список с начала значениями из файла с помощью функции push.
void fill(FILE* file, DoublyLinkedList* list, int* errorCode);

// Функция проверки списка на симметричность.
bool isSymmetrical(DoublyLinkedList* list, int* errorCode);

// Функция удаления списка.
void deleteList(DoublyLinkedList* list, int* errorCode);
