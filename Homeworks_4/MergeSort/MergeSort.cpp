#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> merge(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> merged;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

std::vector<int> mergesort(const std::vector<int>& arr) {
    int size = arr.size();
    if (size <= 1) {
        return arr;
    } 
    int mid = size / 2;
    std::vector<int> left,right;
    for (int i = 0; i < mid; i++) {
        left.push_back(arr[i]);
    }
    for (int i = arr.size() / 2; i < size; i++) {
        right.push_back(arr[i]);
    }
    
    left = mergesort(left);
    right = mergesort(right);
    return merge(left, right);
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

    std::vector<int> sortedArray = mergesort(arr);
    print(sortedArray);
    return 0;
}