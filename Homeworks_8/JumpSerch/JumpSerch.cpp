#include <iostream>
#include <cmath>
#include <sstream>
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
    std::vector<int> arr;
    std::cout << "Enter numbers separated by spaces (e.g., 1 2 3 4): ";
    std::string input;
    std::getline(std::cin, input);

    int number;
    std::istringstream iss(input);
    while (iss >> number) {
        arr.push_back(number);
    }

    int target;
    std::cout << "Enter the target value: ";
    std::cin >> target;

    int result = jumpSearch(arr, target);
    if (result != -1) {
        std::cout << "Found at index: " << result << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    return 0;
}
