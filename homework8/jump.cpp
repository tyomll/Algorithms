#include <iostream>
#include <math.h>

int search(int arr[], int size, int target)
// we check elements step by step,(step = sqrt(num of elem arrays)
// after finding range, it check every element
{
    int step = floor(sqrt(size));
    int index = 0;
    while (arr[index] < target)
    {
        index += step;
    }

    if (arr[index] == target)
    {
        return index;
    }

    for (int i = index; i > (index -= step); i--)
    {
        if (arr[i] = target)
        {
            std::cout << "arr[ " << i << " ] = " << arr[i];
            return index;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]) + 1;

    search(arr, size, 5);

    return 0;
}