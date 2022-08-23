#ifndef SHELL_H
#define SHELL_H

#include "../sort.h"

class Shell : Sort{
    int getGaps(int size);
public:
    using Sort::Sort;
    ~Shell();
    std::chrono::nanoseconds sort(bool random);
    std::string getName();
};

#endif
