#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target){
        return mid;
    } else if (arr[mid] > target) {
        return binarySearch(arr, target ,left, mid - 1);
    } else {
        return binarySearch(arr, target, mid + 1, right);
    }
}

int main() {
    std::vector<int> arr = {-10, 5, 7, 8, 18, 26, 37};
    int target;
    std::cout << "Enter the number you're searching for: ";
    std::cin >> target;

    int result = binarySearch(arr, target, 0, arr.size() - 1);

    if (result == -1) {
        std::cout << "Element not found" << std::endl;
    } else {
        std::cout << "Element found at index: " << result << std::endl;
    }

    return 0;
}

