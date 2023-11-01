#include <iostream>

int search(int arr[], int left, int right, int value)
{
    // function is searching value, it use recursion for divide array to 3 parts
    int mid_left = left + (right - left) / 3;
    int mid_right = right - (right - left) / 3;

    if (arr[mid_left] == value)
    {
        std::cout << "index = " << mid_left << "\n";
        return mid_left;
    }
    else if (arr[mid_right] == value)
    {
        std::cout << "index = " << mid_right << "\n";
        return mid_right;
    }

    else if ((arr[mid_left] < value) && (value < arr[mid_right]))
    {
        search(arr, mid_left + 1, mid_right - 1, value);
    }
    else if (arr[mid_left] > value)
    {
        search(arr, left, mid_left, value);
    }
    else
    {
        search(arr, mid_right, right, value);
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