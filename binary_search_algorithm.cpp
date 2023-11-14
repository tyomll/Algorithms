#include <iostream>

int binarySearch(int array[], int left, int right, int target) {
    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (array[middle] == target)
            return middle;

        if (array[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}

int main() {
    int numbers[] = {2, 3, 4, 10, 40, 45};
    int target = 10;
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int result = binarySearch(numbers, 0, size - 1, target);

    if (result == -1)
        std::cout << "Element is not present." << std::endl;
    else
        std::cout << "Element is present at index " << result << std::endl;

    return 0;
}


