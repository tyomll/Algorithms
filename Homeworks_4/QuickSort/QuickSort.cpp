#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> quicksort(std::vector<int>& arr) {
    if (arr.size() <= 1) {return arr;}

    std::vector<int> left, right, sorted;
    int middle = arr.size() / 2;
    int pivot = arr[middle];

    for (auto element : arr) {
        if (element == arr[middle]) {continue;}

        if (element < arr[middle]) {
            left.push_back(element);
        }
        else {
            right.push_back(element);
        }
    }
    left = quicksort(left);
    right = quicksort(right);

    for (auto element : left) {
        sorted.push_back(element);
    }
    sorted.push_back(pivot);

    for (auto element : right) {
        sorted.push_back(element);
    }
    return sorted;
}

void print(std::vector<int>& arr) {
    std::cout << "Sorted array { ";
    for (auto element : arr) {
        std::cout << element << ", ";
    }
    std::cout << "\b\b }\n";
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
    std::vector<int> sorted = quicksort(arr);
    print(sorted);
    return 0;
}