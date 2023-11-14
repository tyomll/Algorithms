#include <iostream>

void heapify(int values[], int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && values[left] > values[largest])
        largest = left;

    if (right < size && values[right] > values[largest])
        largest = right;

    if (largest != index)
    {
        std::swap(values[index], values[largest]);
        heapify(values, size, largest);
    }
}

void heapSort(int values[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(values, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        std::swap(values[0], values[i]);
        heapify(values, i, 0);
    }
}

void printArray(int values[], int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << values[i] << " ";
    std::cout << "\n";
}

int main()
{
    int data[] = {8, 9, 10, 1, 2, 3};
    int length = sizeof(data) / sizeof(data[0]);

    heapSort(data, length);

    std::cout << "Sorted array is \n";
    printArray(data, length);

    return 0;
}

