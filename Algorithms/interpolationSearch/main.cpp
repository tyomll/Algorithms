#include <iostream>
#include <sstream>
#include <vector>

int interpolationSearch(const std::vector<int>& arr, const int& low,
                        const int& high, const int& target) {
    if (arr.empty()) {
        std::cout << "Array is empty" << std::endl;
        return -1;
    }
    if (arr.size() == 1) {
        if (target == arr[0]) {
            return 0;
        }
        return -1;
    }

    int position;
    if (low <= high && target >= arr[low] && target <= arr[high]) {
        position = low + (((double)(high - low) / (arr[high] - arr[low])) *
                          (target - arr[low]));

        if (arr[position] == target) return position;

        if (arr[position] < target)
            return interpolationSearch(arr, position + 1, high, target);

        if (arr[position] > target)
            return interpolationSearch(arr, low, position - 1, target);
    }
    return -1;
}

std::vector<int> inputArr() {
    std::vector<int> arr;

    std::string arrInput;
    std::cout << "Enter a array of space-separated values: ";

    std::getline(std::cin, arrInput);
    std::istringstream iss(arrInput);
    int num;

    while (std::getline(iss, arrInput, ',')) {
        std::istringstream numStream(arrInput);
        while (numStream >> num) {
            arr.push_back(num);
        }
    }

    if (arr.empty()) {
        std::istringstream spaceIss(arrInput);
        while (spaceIss >> num) {
            arr.push_back(num);
        }
    }

    return arr;
}

int main() {
    std::vector<int> arr = inputArr();
    int target;

    std::cout << "Input the target number: ";
    std::cin >> target;

    std::cout << interpolationSearch(arr, 0, arr.size() - 1, target)
              << std::endl;

    return 0;
}