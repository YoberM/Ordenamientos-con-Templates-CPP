#include <iostream>

template <typename T>
void insertionSort(T* data, int size)
{
    T key;
    int j;
    for(size_t i = 1; i < size; ++i)
    {
        key = data[i];
        j = i - 1;

        while(j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            --j;
        }

        data[j + 1] = key;
    }
}

int main()
{
    int arr[] = {7, 8, 5, 2, 4, 6, 3};
    for(size_t i = 0; i < 7; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    insertionSort<int>(arr, 7);
    for(size_t i = 0; i < 7; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    return 0;
}
