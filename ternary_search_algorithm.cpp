#include <iostream>

int ternarySearch(int left, int right, int target, int arr[]) {
    while (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }

        if (target < arr[mid1]) {
            right = mid1 - 1;
        }
        else if (target > arr[mid2]) {
            left = mid2 + 1;
        }
        else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return -1;
}

int main() {
    int key;

    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(array) / sizeof(array[0]);
    int l = 0;
    int r = size - 1;

    key = 50;
    int result = ternarySearch(l, r, key, array);
    std::cout << "Index of " << key << " is " << result << std::endl;

    key = 80;
    result = ternarySearch(l, r, key, array);
    std::cout << "Index of " << key << " is " << result << std::endl;

    return 0;
}

