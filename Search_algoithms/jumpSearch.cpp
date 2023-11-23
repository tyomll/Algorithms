#include <iostream>
#include <cmath>
#include <vector>

int jumpSearch(const std::vector<int>& arr, int target) {
    int length = arr.size();
    int step = std::sqrt(length);
    int prev = 0;

    while (arr[std::min(step, length) - 1] < target) {
        prev = step;
        step += std::sqrt(length);
        if (prev >= length) {
            return -1;
        }
    }

    while (arr[prev] < target) {
        prev++;

        if (prev == std::min(step, length)) {
            return -1;
        }
    }

    if (arr[prev] == target) {
        return prev;
    }

    return -1;
}

int main() {
    std::vector<int> arr = {5, 10, 15, 20 ,25, 30, 35, 40, 45};
    int target;
    std::cout << "Enter the number you want to search: ";
    std::cin >> target;

    int result = jumpSearch(arr, target);
    if (result != -1) {
        std::cout << "Found at index: " << result << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    return 0;
}