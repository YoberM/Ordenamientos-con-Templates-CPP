#include <iostream>

template <typename T>
int count(T* data, int size, T v)
{
    int counter = 0;
    for(size_t i = 0; i < size; ++i)
        if(data[i] == v)
            ++counter;
    return counter;
}

void countingSort(int* data, int size, int base)
{
    size_t q = 1;
    for(size_t i = 0; i < base; ++i)
        q *= 10;

    int* output = new int[size];
    int* index = new int[q] {0};

    for(size_t i = 0; i < q; ++i) // Counts numbers
        index[i] = count<int>(data, size, i);
    for(size_t i = 1; i < q; ++i) // Sums the Indices
        index[i] += index[i - 1];
    for(int i = size - 1; i >= 0; --i) // Assign the correct ones
        output[--index[data[i]]] = data[i];

    for(size_t i = 0; i < size; ++i)
        data[i] = output[i];

    delete[] output;
    delete[] index;
}

int main()
{
    int arr[] = {1, 4, 1, 2, 7, 5, 2};
    for(size_t i = 0; i < 7; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    countingSort(arr, 7, 1);
    for(size_t i = 0; i < 7; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    return 0;
}
