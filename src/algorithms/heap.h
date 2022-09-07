#ifndef HEAP_H
#define HEAP_H

#include "../sort.h"

class Heap : public Sort{
    void heapify(unsigned int arr[], int size, int i);
    void heapSort(unsigned int arr[], int size);
public:
    using Sort::Sort;
    ~Heap();

    std::chrono::nanoseconds sort(bool random);
    std::string getName();
};

#endif
