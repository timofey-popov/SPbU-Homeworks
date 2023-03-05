#pragma once

#include "../linkedList/linkedList.h"

// Возвращает указатель на отсортированный (от меньших к большим) список. Никак не изменяет переданный на вход список.
// Создаётся новый список. После окончания работы его нужно удалить.
List* mergeSort(List* listToSort, ListErrors* errorCode);
