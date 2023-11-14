#include <iostream>

int interpolationSearch(int arr[], int size, int target) {
    int low = 0, high = (size - 1);

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target)
                return low;
            return -1;
        }

        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if (arr[pos] == target)
            return pos;

        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main() {
    int numbers[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 18;

    int result = interpolationSearch(numbers, size, target);

    if (result != -1)
        std::cout << "Element found at index " << result <<"\n";
    else
        std::cout << "Element not found." <<"\n";

    return 0;
}

