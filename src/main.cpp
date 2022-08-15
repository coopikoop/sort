#include <iostream>
#include <chrono>
// #include <random>

#include "functions.h"

#include "insertion.h"
#include "selection.h"
#include "merge.h"
#include "quick.h"
#include "shell.h"
#include "bubble.h"
#include "comb.h"
#include "exchange.h"

// std::random_device rd;
// unsigned int x = rd();
unsigned int x {123};
unsigned int xorshift32() {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return x;
}

#define TIMER(func)                                                             \
    auto start = std::chrono::high_resolution_clock::now();                     \
    func(arr, size);                                                            \
    auto stop = std::chrono::high_resolution_clock::now();                      \
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

int main() {
    int size {100000};
    int runs {5};
    unsigned int* arr;
    arr = new unsigned int[size];
    int runtime {0};

    // Insertion insert;
    // Selection select;
    // Merge merge;
    // Quick quick;
    // Shell shell;
    // Bubble bubble;
    // Comb comb;
    Exchange exchange;

    for (int i = 0; i < runs; ++i) {
        for (int i = 0; i < size; ++i) {
            arr[i] = xorshift32() % 1000000 + 1;
        }
        // printArr(arr, size);
        TIMER(exchange.sort);
        // printArr(arr, size);
        runtime += time.count();
        std::cout << "Sort took " << time.count() << " milliseconds" << std::endl;
    }

    std::cout << "Average sort time: " << runtime / runs << " milliseconds" << std::endl;

    delete arr;
}
