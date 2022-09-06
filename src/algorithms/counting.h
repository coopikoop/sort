#ifndef COUNTING_H
#define COUNTING_H

#include "../sort.h"

class Counting : Sort {
    void countingSort(unsigned int arr[], size_t size);
public:
    using Sort::Sort;
    ~Counting();

    std::chrono::nanoseconds sort(bool random);
    std::string getName();
};

#endif
