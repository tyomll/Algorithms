#include <iostream>
#include <vector>

void printArray(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int partition(std::vector<int> &arr, int low, int high)
{
    int mid = (low + high) / 2;
    int pivot = arr[mid];
    int i = low;
    int j = high;

    std::cout << "priot is : " << pivot << "\n";

    while (true)
    {
        printArray(arr);
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i >= j)
        {
            std::cout << "i returned : " << j;

            return j;
        }

        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        std::cout << "  low = " << low << "  high = " << high << "  pi = " << pi << "\n \n";
        std::cout << "------------------------------- \n";

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int size = arr.size();

    std::cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
