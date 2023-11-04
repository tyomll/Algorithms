#include <iostream>

void find_target_boarders(int arr[], int target, int size)
{
    // this function find boarders
    int left = target - 1;
    int right = target + 1;

    while (left >= 0 && arr[left] == arr[target])
    {
        left--;
    }

    while (right < size && arr[right] == arr[target])
    {
        right++;
    }

    std::cout << "[" << left + 1 << ", " << right - 1 << "]";
}

void find_target(int arr[], int left, int right, int value, int size)
{
    // function is targeting value, it uses recursion to divide the array into 3 parts
    int mid_left = left + (right - left) / 3;
    int mid_right = right - (right - left) / 3;

    if (arr[mid_left] == value)
    {
        find_target_boarders(arr, mid_left, size);
    }
    else if (arr[mid_right] == value)
    {
        find_target_boarders(arr, mid_right, size);
    }

    else if ((arr[mid_left] < value) && (value < arr[mid_right]))
    {
        find_target(arr, mid_left + 1, mid_right - 1, value, size);
    }
    else if (arr[mid_left] > value)
    {
        find_target(arr, left, mid_left - 1, value, size);
    }
    else
    {
        find_target(arr, mid_right + 1, right, value, size);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 5, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    find_target(arr, 0, size - 1, 5, size);

    return 0;
}
