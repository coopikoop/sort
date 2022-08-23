#include <iostream>
#include <random>

#include "functions.h"

void swap(unsigned int &a, unsigned int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void printArr(unsigned int arr[], unsigned int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

unsigned int xorshift32(unsigned int x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

void randomize(size_t size, unsigned int arr[]) {
    std::random_device rd;
    unsigned int x = rd();
    for (int i = 0; i < size; ++i) {
        x = xorshift32(x);
        arr[i] = x;
    }
}

void fill(size_t size, unsigned int arr[]) {
    for (int i = 1; i <= size; ++i) {
        arr[i - 1] = i;
    }
}
