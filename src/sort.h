#ifndef SORT_H
#define SORT_H

#include <cstddef>
#include <chrono>
#include <string>

class Sort {
    unsigned int* arr;
    size_t size;

protected:
    void swap(unsigned int &a, unsigned int &b);

public:
    Sort(size_t size);
    ~Sort();

    virtual std::chrono::nanoseconds sort(bool random) = 0;

    size_t getSize();
    void setSize(size_t size);
    unsigned int* getArr();
    void setArr(unsigned int arr[]);
};

#endif
