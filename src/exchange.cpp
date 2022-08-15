#include "exchange.h"
#include "functions.h"

void Exchange::sort(unsigned int arr[], int size) {
    for (int n = 0; n < size; ++n) {
        for (int i = n; i < size; ++i) {
            if (arr[i] < arr[n]) {
                swap(arr[i], arr[n]);
            }
        }
    }
}
