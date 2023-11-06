#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>

int binarysearch(std::vector<int>& arr, int search, int start, int end) {
    if (start > end) {
        return -1;
    }
    int center = (start + end) / 2;
    if (arr[center] == search) {
        return center;
    }
    else if (search < arr[center]) {
        return binarysearch(arr, search, start, center - 1);
    }
    else {
        return binarysearch(arr, search, center + 1, end);
    }
}

int ExponentialSearch(std::vector<int>& arr, int target) {
    int border = 1;
    int length = arr.size() - 1;
    while (border < length && arr[border] < target) {
        border *= 2;
        if (border > length) {
            border = length;
        }
    }
    return binarysearch(arr, target, border / 2, border);
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

    int result = ExponentialSearch(arr, target);
    if (result != -1) {
        std::cout << "Found at index: " << result << std::endl;
    } else {
        std::cout << "Not found. " << result << std::endl;
    }

    return 0;
}
