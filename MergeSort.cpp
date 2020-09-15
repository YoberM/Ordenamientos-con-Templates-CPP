#include <iostream>

template <typename T>
void mergeHalves(T* data, T* temp, int leftStart, int rightEnd)
{
    int leftEnd = (leftStart + rightEnd) / 2;
    int rightStart = leftEnd + 1;
    int size = rightEnd - leftStart + 1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while(left <= leftEnd && right <= rightEnd)
    {
        if(data[left] <= data[right])
            temp[index++] = data[left++];
        else
            temp[index++] = data[right++];
    }

    for(size_t i = 0; i < leftEnd - left + 1; ++i)
        temp[index + i] = data[left + i];
    for(size_t i = 0; i < rightEnd - right + 1; ++i)
        temp[index + i] = data[right + i];
    for(size_t i = leftStart; i <= rightEnd; ++i)
        data[i] = temp[i];
}

template <typename T>
void merge(T* data, T* temp, int leftStart, int rightEnd)
{
    if(leftStart >= rightEnd)
        return;
    int middle = (leftStart + rightEnd) / 2;
    merge(data, temp, leftStart, middle);
    merge(data, temp, middle + 1, rightEnd);
    mergeHalves(data, temp, leftStart, rightEnd);
}

template <typename T>
void mergeSort(T* data, int size)
{
    T* temp = new T[size];
    merge(data, temp, 0, size - 1);
    delete[] temp;
}

int main()
{
    int arr[] = {10, 5, 2, 7, 4, 9, 12, 1, 8, 6, 11, 3};
    for(size_t i = 0; i < 12; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    mergeSort<int>(arr, 12);
    for(size_t i = 0; i < 12; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    return 0;
}
