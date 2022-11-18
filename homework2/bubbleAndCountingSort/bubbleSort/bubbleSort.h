#pragma once

// Функция для вывода массива на экран.
// Принимает указатель на массив, размер массива и количество элементов в одной строке вывода.
void arrayPrint(int* arrayToPrint, int printingArraySize, int numberOfElementsInOneString);

// Сортировка пузырьком.
// На вход принимает указатель на сортируемый массив и его размер.
void bubbleSort(int* arrayToSort, int arraySize);

// Функция для сравнения отсортированного массива с образцом.
// На вход принимает указатели на эти два массива и их размер.
// В цикле бежит по соответсвующим элементам массива и сравнивает их.
// Возвращает true, если массивы совпадают, и false в противном случае.
bool comparisonForTest(int* arrayForTest, int* referenceArray, size_t arraySize);

//Функция с тестами.
//Возвращает true в случае, если всё работает правильно и false в противном случае.
bool testBubbleSort(int* numberOfFailedTest);
