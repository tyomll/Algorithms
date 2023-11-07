#include <iostream>

int search(int arr[], int left, int right, int value)
{
    // just binary search
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

int exponential_search(int arr[], int target, int size)
{
    // this function is some type of linear search, but it checks by i = i*2 logic
    // and when finds value which is greater then target calls binary search

    if (arr[0] == target)
    {
        return 0;
    }

    for (int i = 0; i < size; i *= 2)
    {
        if (arr[i] > target)
        {
            search(arr, i / 2, i, target);
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    search(arr, 0, size, 7);

    return 0;
}