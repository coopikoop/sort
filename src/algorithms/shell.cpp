#include "shell.h"
#include "../functions.h"

#include <math.h>

int gapsArr[] {1, 4, 10, 23, 57, 132, 301, 701, 1577, 3548, 7983, 17961,
        40412, 90927, 204585, 460316, 1035711, 2330349, 5243285, 11797391,
        26544129, 59724290, 134379652, 302354217, 680296988, 1530668223};

Shell::~Shell() {}

int Shell::getGaps(int size) {
    int i = 25;
    while (size / 2 < gapsArr[i])
        --i;
    return i;
}

std::chrono::nanoseconds Shell::sort(bool random) {
    size_t size = getSize();
    unsigned int* arr = getArr();
    if (random) {
        randomize(size, arr);
    } else {
        fill(size, arr);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (int gapIndex = getGaps(size); gapIndex >= 0; --gapIndex) {
        int gap = gapsArr[gapIndex];
        for (int i = gap; i < size; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; (j >= gap) && (arr[j - gap] > temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
}

std::string Shell::getName() {
    return "Shell";
}
