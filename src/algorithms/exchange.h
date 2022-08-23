#ifndef EXCHANGE_H
#define EXCHANGE_H

#include "../sort.h"

class Exchange : Sort{
public:
    using Sort::Sort;
    ~Exchange();

    std::chrono::nanoseconds sort(bool random);
    std::string getName();
};

#endif
