#ifndef MERGE_H
#define MERGE_H

class Merge {
    void mergeSort(unsigned int arr[], int start, int end);
    void merge(unsigned int arrp[], int start, int mid, int end);
public:
    void sort(unsigned int arr[], int size);
};

#endif
