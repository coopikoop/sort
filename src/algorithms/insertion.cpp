#include "insertion.h"
#include "../functions.h"

Insertion::~Insertion() {}

std::chrono::nanoseconds Insertion::sort(bool random) {
    size_t size = getSize();
    unsigned int* arr = getArr();
    if (random) {
        randomize(size, arr);
    } else {
        fill(size, arr);
    }

    auto start = std::chrono::steady_clock::now();

    for (int i = 1; i < size; ++i) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            --j;
        }
    }

    auto stop = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
}

std::string Insertion::getName() {
    return "Insertion";
}
