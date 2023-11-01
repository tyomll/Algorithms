#include <iostream>
#include <vector>

int search(int arr[], int left, int right, int value)
{
    int mid = left + (right - left) / 2;
    if (arr[mid] == value)
    {
        std::cout << "index = " << mid;
        return mid;
    }
    else if (arr[mid] < value)
    {
        search(arr, mid, right, value);
    }
    else
    {
        search(arr, left, mid, value);
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    search(arr, 0, size, 5);

    return 0;
}