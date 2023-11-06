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

std::pair<int, int> searchIndexes(std::vector<int>& arr, int target) {
    int index = ternarySearch(arr, target, 0, arr.size() - 1);
    if (index != -1) {
        int left = index;
        int right = index;
        while (arr[left] == target) {
            left--;
        }
        while (arr[right] == target) {
            right++;
        }

        return std::pair<int, int>(left + 1, right - 1);
    }
    
    return std::pair<int, int>(-1, -1);
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
    std::pair<int, int> result = searchIndexes(arr, 8);
    std::cout << "[" << result.first << ", " << result.second << "]\n";
}