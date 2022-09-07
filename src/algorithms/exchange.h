#ifndef EXCHANGE_H
#define EXCHANGE_H

#include "../sort.h"

class Exchange : public Sort{
public:
    using Sort::Sort;
    ~Exchange();

    std::chrono::nanoseconds sort(bool random);
    std::string getName();
};

#endif
