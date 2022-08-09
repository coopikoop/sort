#include "insertion.h"
#include "functions.h"

void Insertion::sort(unsigned int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            --j;
        }
    }
}
