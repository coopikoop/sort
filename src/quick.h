#ifndef QUICK
#define QUICK

class Quick {
    void quickSort(unsigned int arr[], int start, int end);
    int partition(unsigned int arr[], int start, int end);
public:
    void sort(unsigned int arr[], int size);
};

#endif
