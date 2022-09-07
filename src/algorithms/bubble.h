#ifndef BUBBLE_H
#define BUBBLE_H

#include "../sort.h"

class Bubble : public Sort {
public:
    using Sort::Sort;
    ~Bubble();

    std::chrono::nanoseconds sort(bool random);
    std::string getName();
};

#endif
