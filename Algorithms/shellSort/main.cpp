#include <iostream>
#include <sstream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    int interval = arr.size() / 2;

    while (interval > 0) {
        size_t leftPointer, rightPointer;
        int currentValue;

        for (size_t rightPointer = interval; rightPointer < arr.size(); rightPointer++) {
            leftPointer = rightPointer;
            currentValue = arr[leftPointer];

            while (leftPointer > interval - 1 && arr[leftPointer - interval] > currentValue) {
                arr[leftPointer] = arr[leftPointer - interval];
                leftPointer -= interval;
            }

            arr[leftPointer] = currentValue;
        }
        interval /= 2;
    }
}

std::vector<int> inputArr() {
    std::vector<int> arr;

    std::string arrInput;
    std::cout << "Enter a array of space-separated values: ";

    std::getline(std::cin, arrInput);
    std::istringstream iss(arrInput);
    int num;

    while (iss >> num) {
        arr.push_back(num);
    }

    return arr;
}

int main() {
    std::vector<int> arr = inputArr();
    shellSort(arr);

    for (const int& el : arr) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;

    return 0;
}