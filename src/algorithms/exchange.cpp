#include "exchange.h"
#include "../functions.h"

Exchange::~Exchange() {}

std::chrono::nanoseconds Exchange::sort(bool random) {
    size_t size = getSize();
    unsigned int* arr = getArr();
    if (random) {
        randomize(size, arr);
    } else {
        fill(size, arr);
    }

    auto start = std::chrono::steady_clock::now();

    for (int n = 0; n < size; ++n) {
        for (int i = n; i < size; ++i) {
            if (arr[i] < arr[n]) {
                swap(arr[i], arr[n]);
            }
        }
    }

    auto stop = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
}

std::string Exchange::getName() {
    return "Exchange";
}
