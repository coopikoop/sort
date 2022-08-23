#ifndef SELECTION_H
#define SELECTION_H

#include "../sort.h"

class Selection : Sort {
public:
    using Sort::Sort;
    ~Selection();

    std::chrono::nanoseconds sort(bool random);
    std::string getName();
};

#endif
