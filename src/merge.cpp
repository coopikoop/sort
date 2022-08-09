#include "merge.h"

void Merge::sort(unsigned int arr[], int size) {
    int start {0};
    int end {size};
    mergeSort(arr, start, end);
}

void Merge::mergeSort(unsigned int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int mid {start + (end - start) / 2};
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void Merge::merge(unsigned int arr[], int start, int mid, int end) {
    int arr1size {mid - start + 1};
    int arr2size {end - mid};
    unsigned int arr1[arr1size];
    unsigned int arr2[arr2size];

    for (int i = 0; i < arr1size; ++i)
        arr1[i] = arr[start + i];
    for (int i = 0; i < arr2size; ++i)
        arr2[i] = arr[mid + i + 1];

    int i = 0;
    int j = 0;
    int k = start;

    while (i < arr1size && j < arr2size) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            ++i;
            ++k;
        } else {
            arr[k] = arr2[j];
            ++j;
            ++k;
        }
    }

    while (i < arr1size) {
        arr[k] = arr1[i];
        ++i;
        ++k;
    }

    while (j < arr2size) {
        arr[k] = arr2[j];
        ++j;
        ++k;
    }
}

/*
    3 2 4 1
  3 2     4 1
 3   2   4   1
  2 3     1 4
    1 2 3 4
*/
