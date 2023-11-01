#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int ternarySearch(const std::vector<int>& arr, int search, int left, int right) {
    if (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = left + 2 * (right - left) / 3;

        if (arr[mid1] == search) {
            return mid1;
        }
        if (arr[mid2] == search) {
            return mid2;
        }
        if (search < arr[mid1]) {
            return ternarySearch(arr, search, left, mid1 - 1);
        } else if (search > arr[mid2]) {
            return ternarySearch(arr, search, mid2 + 1, right);
        } else {
            return ternarySearch(arr, search, mid1 + 1, mid2 - 1);
        }
    }

    return -1;
}

int main() {
    std::vector<int> arr;
    std::cout << "Enter numbers separated by spaces (e.g., 1 2 3 4): ";
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    int number;
    while (iss >> number) {
        arr.push_back(number);
    }
    std::cout << ternarySearch(arr, 5, 0, arr.size() - 1) << std::endl;
}