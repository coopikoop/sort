#ifndef COMB_H
#define COMB_H

#include "../sort.h"

class Comb : Sort{
    int nextGap(int gap);
public:
    using Sort::Sort;
    ~Comb();

    std::chrono::nanoseconds sort(bool random);
    std::string getName();
};

#endif
