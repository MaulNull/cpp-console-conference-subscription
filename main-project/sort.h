#ifndef SORT_H
#define SORT_H

#include "lecture_subscription.h"

// ������� ���������

// 1. �� ������������ ������ (������� ����� finish � start), ��������
int compareDurationDesc(const void* a, const void* b);

// 2. �� ������� ������, � ��� ��������� � �� �������� ������, �� �����������
int compareAuthorTitleAsc(const void* a, const void* b);

// ������ ����������

// ����� ���������
void swap(struct lecture_subscription* a, struct lecture_subscription* b);

// ������������� ���������� (Heap sort)
void heapify(struct lecture_subscription arr[], int n, int i, int (*comp)(const void*, const void*));
void heapSort(struct lecture_subscription arr[], int n, int (*comp)(const void*, const void*));

// ���������� ��������
void merge(struct lecture_subscription arr[], int l, int m, int r, int (*comp)(const void*, const void*));
void mergeSortRec(struct lecture_subscription arr[], int l, int r, int (*comp)(const void*, const void*));
void mergeSort(struct lecture_subscription arr[], int n, int (*comp)(const void*, const void*));

// ������� ��� mergeSort � ������ ����������
void mergeSortWrapper(struct lecture_subscription* arr, int size, int (*cmp)(const void*, const void*));

// ���� ���������� �� ������� ���������� � ���������
typedef void (*SortFunc)(struct lecture_subscription*, int, int (*)(const void*, const void*));
typedef int (*CompareFunc)(const void*, const void*);

// ������ ���������� �� ������� ����������
extern SortFunc sortMethods[];

// ������ ���������� �� ������� ���������
extern CompareFunc compareFuncs[];

#endif
