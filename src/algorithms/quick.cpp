#include "quick.h"
#include "../functions.h"

Quick::~Quick() {}

std::chrono::nanoseconds Quick::sort(bool random) {
    size_t size = getSize();
    unsigned int* arr = getArr();
    if (random) {
        randomize(size, arr);
    } else {
        fill(size, arr);
    }

    auto start = std::chrono::steady_clock::now();

    int first {0};
    int end = size - 1;
    quickSort(arr, first, end);

    auto stop = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
}

void Quick::quickSort(unsigned int arr[], int start, int end) {
    if (start >= end) {
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
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

std::string Quick::getName() {
    return "Quick";
}
