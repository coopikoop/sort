#include "comb.h"
#include "functions.h"
#include <math.h>

int Comb::nextGap(int gap) {
    return gap == 1 ? 1 : floor(gap * 10 / 13);
}

void Comb::sort(unsigned int arr[], int size) {
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
}
