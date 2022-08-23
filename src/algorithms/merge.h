#ifndef MERGE_H
#define MERGE_H

#include "../sort.h"

class Merge : Sort {
    void mergeSort(unsigned int arr[], int start, int end);
    void merge(unsigned int arrp[], int start, int mid, int end);
public:
    using Sort::Sort;
    ~Merge();

    std::chrono::nanoseconds sort(bool random);
    std::string getName();
};

#endif
