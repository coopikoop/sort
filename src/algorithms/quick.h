#ifndef QUICK_H
#define QUICK_H

#include "../sort.h"

class Quick : public Sort{
    void quickSort(unsigned int arr[], int start, int end);
    int partition(unsigned int arr[], int start, int end);
public:
    using Sort::Sort;
    ~Quick();

    std::chrono::nanoseconds sort(bool random);
    std::string getName();
};

#endif
