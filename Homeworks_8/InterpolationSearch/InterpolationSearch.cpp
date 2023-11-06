#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>

int interpolationSearch(std::vector<int>& arr, int target) {
    int high = arr.size() - 1;
    int low = 0, position;
    while (low < high && target <= arr[high] && target >= arr[low]) {
        position = low + ((high - low) / (arr[high] - arr[low])) * (target - arr[low]);
        if (target == arr[position]) {
            return position;
        }
        if (target > arr[position]) {
            low++;
        }
        else {
            high--;
        }
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

    int result = interpolationSearch(arr, target);
    if (result != -1) {
        std::cout << "Found at index: " << result << std::endl;
    } else {
        std::cout << "Not found. " << result << std::endl;
    }

    return 0;
}
