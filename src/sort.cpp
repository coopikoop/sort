#include "sort.h"

void Sort::swap(unsigned int &a, unsigned int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

Sort::Sort(size_t size) {
    this->size = size;
    arr = new unsigned int[size];
}

Sort::~Sort() {
    delete arr;
}

size_t Sort::getSize() {
    return size;
}

void Sort::setSize(size_t size) {
    this->size = size;
}

unsigned int* Sort::getArr() {
    return arr;
}

void Sort::setArr(unsigned int arr[]) {
    this->arr = arr;
}
