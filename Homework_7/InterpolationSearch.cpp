#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int interpolationSearch(std::vector<int>& arr, int low, int high, int target) {
    if (low <= high && target >= arr[low] && target <= arr[high]) {
        int position = low + (((target - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        if (arr[position] == target) {
            return position;
        }
        if (arr[position - 1] == target) {
            return position - 1;
        }
        if (arr[position + 1] == target) {
            return position + 1;
        }

        if (target < arr[position]) {
            return interpolationSearch(arr, low, position - 1, target);
        }

        if (target > arr[position]) {
            return interpolationSearch(arr, position + 1, high, target);
        }
    }

    return -1;
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

    int index = interpolationSearch(arr, 0, arr.size() - 1, target);

    if (index == -1) {
        std::cout << "The element you are looking for does not exist in the array\n";
    }
    else {
        std::cout << "The index of the element to be searched for is " << index << std::endl;
    }

    return 0;
    
}