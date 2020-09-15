#include <iostream>

template <typename T>
void swap(T& v1, T& v2)
{
    T t = v1;
    v1 = v2;
    v2 = t;
}

template <typename T>
void bubbleSort(T* data, int size)
{
    int j = size - 1;
    while(j--)
    {
        for(size_t i = 0; i < j; ++i)
        {
            if(data[i] > data[i + 1])
                swap<T>(data[i], data[i + 1]);
        }
    }
}

int main()
{
    int arr[] = {5, 1, 4, 2, 8, 9};
    for(size_t i = 0; i < 6; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    bubbleSort<int>(arr, 6);
    for(size_t i = 0; i < 6; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    return 0;
}
