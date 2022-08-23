#ifndef INSERTION_H
#define INSERTION_H

#include "../sort.h"

class Insertion : Sort{
public:
    using Sort::Sort;
    ~Insertion();

    std::chrono::nanoseconds sort(bool random);
    std::string getName();
};

#endif
