#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>

// Функции сравнения

// 1. По длительности лекции (разница между finish и start)
int compareDurationDesc(const void* a, const void* b) {
    const struct lecture_subscription* la = (const struct lecture_subscription*)a;
    const struct lecture_subscription* lb = (const struct lecture_subscription*)b;

    int durationA = (la->finish.hours - la->start.hours) * 60 + (la->finish.minutes - la->start.minutes);
    int durationB = (lb->finish.hours - lb->start.hours) * 60 + (lb->finish.minutes - lb->start.minutes);

    return durationB - durationA; // убывание
}

// 2. По фамилии автора, а при равенстве — по названию лекции
int compareAuthorTitleAsc(const void* a, const void* b) {
    const struct lecture_subscription* la = (const struct lecture_subscription*)a;
    const struct lecture_subscription* lb = (const struct lecture_subscription*)b;

    int cmpLastName = strcmp(la->author.last_name, lb->author.last_name);
    if (cmpLastName != 0)
        return cmpLastName; // по фамилии

    return strcmp(la->title, lb->title); // по названию лекции
}

// Методы сортировки

// Обмен элементов
void swap(struct lecture_subscription* a, struct lecture_subscription* b) {
    struct lecture_subscription temp = *a;
    *a = *b;
    *b = temp;
}

// Пирамидальная сортировка (Heap sort)
void heapify(struct lecture_subscription arr[], int n, int i, int (*comp)(const void*, const void*)) {
    int largest = i; // корень
    int l = 2 * i + 1; // левый ребенок
    int r = 2 * i + 2; // правый ребенок

    if (l < n && comp(&arr[l], &arr[largest]) > 0)
        largest = l;

    if (r < n && comp(&arr[r], &arr[largest]) > 0)
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, comp);
    }
}

void heapSort(struct lecture_subscription arr[], int n, int (*comp)(const void*, const void*)) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comp);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, comp);
    }
}

// Сортировка слиянием
void merge(struct lecture_subscription arr[], int l, int m, int r, int (*comp)(const void*, const void*)) {
    int n1 = m - l + 1;
    int n2 = r - m;

    struct lecture_subscription* L = new lecture_subscription[n1];
    struct lecture_subscription* R = new lecture_subscription[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (comp(&L[i], &R[j]) <= 0) { // <= для стабильности или по условию
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete L;
    delete R;
}

void mergeSortRec(struct lecture_subscription arr[], int l, int r, int (*comp)(const void*, const void*)) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortRec(arr, l, m, comp);
        mergeSortRec(arr, m + 1, r, comp);
        merge(arr, l, m, r, comp);
    }
}

void mergeSort(struct lecture_subscription arr[], int n, int (*comp)(const void*, const void*)) {
    mergeSortRec(arr, 0, n - 1, comp);
}

// Обертка для mergeSort с нужной сигнатурой
void mergeSortWrapper(struct lecture_subscription* arr, int size, int (*cmp)(const void*, const void*)) {
    mergeSort(arr, size, cmp);
}

// Массив указателей на функции сортировки
typedef void (*SortFunc)(struct lecture_subscription*, int, int (*)(const void*, const void*));
SortFunc sortMethods[] = { heapSort, mergeSortWrapper };



// Массив указателей на функции сравнения
typedef int (*CompareFunc)(const void*, const void*);
CompareFunc compareFuncs[] = { compareDurationDesc  , compareAuthorTitleAsc };

