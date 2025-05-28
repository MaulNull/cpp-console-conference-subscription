#ifndef SORT_H
#define SORT_H

#include "lecture_subscription.h"

// Функции сравнения

// 1. По длительности лекции (разница между finish и start), убывание
int compareDurationDesc(const void* a, const void* b);

// 2. По фамилии автора, а при равенстве — по названию лекции, по возрастанию
int compareAuthorTitleAsc(const void* a, const void* b);

// Методы сортировки

// Обмен элементов
void swap(struct lecture_subscription* a, struct lecture_subscription* b);

// Пирамидальная сортировка (Heap sort)
void heapify(struct lecture_subscription arr[], int n, int i, int (*comp)(const void*, const void*));
void heapSort(struct lecture_subscription arr[], int n, int (*comp)(const void*, const void*));

// Сортировка слиянием
void merge(struct lecture_subscription arr[], int l, int m, int r, int (*comp)(const void*, const void*));
void mergeSortRec(struct lecture_subscription arr[], int l, int r, int (*comp)(const void*, const void*));
void mergeSort(struct lecture_subscription arr[], int n, int (*comp)(const void*, const void*));

// Обертка для mergeSort с нужной сигнатурой
void mergeSortWrapper(struct lecture_subscription* arr, int size, int (*cmp)(const void*, const void*));

// Типы указателей на функции сортировки и сравнения
typedef void (*SortFunc)(struct lecture_subscription*, int, int (*)(const void*, const void*));
typedef int (*CompareFunc)(const void*, const void*);

// Массив указателей на функции сортировки
extern SortFunc sortMethods[];

// Массив указателей на функции сравнения
extern CompareFunc compareFuncs[];

#endif
