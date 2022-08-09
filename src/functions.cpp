#include <iostream>

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
