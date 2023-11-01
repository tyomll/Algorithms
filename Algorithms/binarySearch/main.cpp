#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, const int& target, int& middle) {
    if (middle < arr.size() && middle >= 0) {
        if (target == arr[middle]) {
            return middle;
        }
        if (target > arr[middle]) {
            middle++;
        }
        if (target < arr[middle]) {
            middle--;
        }
        return binarySearch(arr, target, middle);
    }

    return -1;
}

int binarySearch(const std::vector<int>& arr, const int& target) {
    int middle = arr.size() / 2;
    return binarySearch(arr, target, middle);
}

int main() {
    int target = 8;

    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 10};

    std::cout << binarySearch(arr, target) << std::endl;
    return 0;
}