#include <iostream>
#include <vector>

int interpolationSearch(std::vector<int>& arr, int low, int high, int target) {
    if (low <= high && target >= arr[low] * target <= arr[high]) {
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

std::vector<int> importVector() {
    std::string input;
    std::vector<int> arr;
    std::cout << "Enter the array numbers. Enter 'stop' to stop.\n";
    while (true) {
        std::cin >> input;
        if (input == "stop") {
            break;
        }

        int number = std::stoi(input);
        arr.push_back(number);
    }

    return arr;
}

int main() {
    std::vector<int> arr = importVector();
    
    std::cout << "Enter the target: ";
    int target;
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