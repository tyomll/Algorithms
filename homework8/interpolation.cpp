#include <iostream>

int search(int arr[], int end, int target)
{

    int start = 0;

    while (start < end)
    {
        int pos = start + (((end - start) / (arr[end] - arr[start])) * (target - arr[start]));

        if (arr[pos] == target)
        {
            return pos;
        }
        else if (arr[pos] < target)
        {
            start = pos + 1;
        }
        else
        {
            end = pos - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    search(arr, size, 5);

    return 0;
}