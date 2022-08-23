#include "comb.h"
#include "../functions.h"
#include <math.h>

Comb::~Comb() {}

int Comb::nextGap(int gap) {
    return gap == 1 ? 1 : floor(gap * 10 / 13);
}

std::chrono::nanoseconds Comb::sort(bool random) {
    size_t size = getSize();
    unsigned int* arr = getArr();
    if (random) {
        randomize(size, arr);
    } else {
        fill(size, arr);
    }

    auto start = std::chrono::high_resolution_clock::now();

    int gap = size;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = nextGap(gap);
        swapped = false;

        for (int i = 0; i < size - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
}

std::string Comb::getName() {
    return "Comb";
}
