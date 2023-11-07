#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

int binarySearch(std::vector<int>& arr, int left, int right, int target) {
    if (left <= right) {
        int index = (left + right) / 2;
        if (arr[index] == target) {
            return index;
        }
        else if (target < arr[index]) {
            return binarySearch(arr, left, index - 1, target);
        }
        else if (target > arr[index]) {
            return binarySearch(arr, index + 1, right, target);
        }
    }

    return -1;
}

int jumpSearch(std::vector<int>& arr, int target) {
    if (arr.empty()) {
        return -1;
    }
    
    int step = std::sqrt(arr.size());
    int index = 0;
    while (index <= arr.size() - 1) {
        if (arr[index] == target) {
            return index;
        }
        else if (arr[index] < target) {
            index += step;
        }
        else if (arr[index] > target) {
            return binarySearch(arr, index - step, index, target);
        }
    }

    return binarySearch(arr, index - step, arr.size() - 1, target);
}

std::vector<int> inputVector() {
    std::string userRow, clearRow;
    std::vector<int> result;
    std::cout << "Import an array of integer values separated by spaces: For example: 4 8 9 10\n";
    std::getline(std::cin, userRow);
    for (int i = 0; i < userRow.length(); ++i) {
        if (std::isdigit(userRow[i])) {
            clearRow += userRow[i];
        }
        else {
            clearRow += " ";
        }
    }

    std::istringstream iss(clearRow);
    int number;
    while (iss >> number) {
        result.push_back(number);
    }

    return result;
}

void printVector(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Array[" << i << "] = " << arr[i] << std::endl;
    }
}

int main() {
    std::vector<int> arr = inputVector();
    int target;

    std::cout << "Enter the element to be searched for, of type integer: ";
    std::cin >> target;

    int index = jumpSearch(arr, target);

    if (index == -1) {
        std::cout << "The element you are looking for does not exist in the array\n";
    }
    else {
        std::cout << "The index of the element to be searched for is " << index << std::endl;
    }

    return 0;
}