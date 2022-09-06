#include "counting.h"
#include "../functions.h"
#include <algorithm>

Counting::~Counting() {}

std::chrono::nanoseconds Counting::sort(bool random) {
    size_t size = getSize();
    unsigned int* arr = getArr();
    if (random) {
        randomize(size, arr);
    } else {
        fill(size, arr);
    }

    auto start = std::chrono::steady_clock::now();

    countingSort(arr, size);

    auto stop = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
}

void Counting::countingSort(unsigned int arr[], size_t size) {
    unsigned int max = *std::max_element(arr, arr + size);
    unsigned int min = *std::min_element(arr, arr + size);
    unsigned int range = max - min + 1;

    unsigned int* count = new unsigned int[range];
    unsigned int* output = new unsigned int[size];
    memset(count, 0, sizeof(*count));
    memset(output, 0, sizeof(*output));

    for (size_t i = 0; i < size; i++) {
        count[arr[i] - min]++;
    }

    for (size_t i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (size_t i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

std::string Counting::getName() {
    return "Counting";
}
