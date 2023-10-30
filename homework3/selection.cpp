#include <iostream>

void fill_array(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        std::cout << "\n arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}

void sort_array(int arr[], int size)
{
    int min, index;

    for (int i = 0; i < size - 2; i++)
    {
        min = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }
        if (min != i)
        {
            arr[i] = arr[i] + arr[index];
            arr[index] = arr[i] - arr[index];
            arr[i] = arr[i] - arr[index];
        }
    }
}

void print_array(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        std::cout << "\n arr[" << i << "] = " << arr[i] << "\n";
    }
}

int main()
{
    int size;

    std::cout << "enter the length of array : ";
    std::cin >> size;

    int arr[size];

    fill_array(arr, size);
    sort_array(arr, size);
    print_array(arr, size);
    return 0;
}