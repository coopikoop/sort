#include "bubble.h"
#include "../functions.h"

Bubble::~Bubble() {}

std::chrono::nanoseconds Bubble::sort(bool random) {
    size_t size = getSize();
    unsigned int* arr = getArr();
    if (random) {
        randomize(size, arr);
    } else {
        fill(size, arr);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
}

std::string Bubble::getName() {
    return "Bubble";
}
