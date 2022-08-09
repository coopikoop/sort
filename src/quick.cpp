#include "quick.h"
#include "functions.h"

void Quick::sort(unsigned int arr[], int size) {
    int start {0};
    int end {size - 1};
    quickSort(arr, start, end);
}

void Quick::quickSort(unsigned int arr[], int start, int end) {
    if (end - start <= 1) {
        return;
    }

    int partIndex = partition(arr, start, end);

    quickSort(arr, start, partIndex - 1);
    quickSort(arr, partIndex + 1, end);
}

int Quick::partition(unsigned int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}
