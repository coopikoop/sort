#include "selection.h"
#include "../functions.h"

Selection::~Selection() {}

std::chrono::nanoseconds Selection::sort(bool random) {
    size_t size = getSize();
    unsigned int* arr = getArr();
    if (random) {
        randomize(size, arr);
    } else {
        fill(size, arr);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
}

std::string Selection::getName() {
    return "Selection";
}
