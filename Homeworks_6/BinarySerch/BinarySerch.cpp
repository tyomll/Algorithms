#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int binarysearch(std::vector<int>& arr, int search, int start, int end) {
    int center = (start + end) / 2;
    if (arr[center] == search) {
        return center;
    }
    else if (search < arr[center]) {
        return binarysearch(arr, search, start, center - 1);
    }
    else if (search > arr[center]) {
        return binarysearch(arr, search, center + 1, end);
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
    std::cout << binarysearch(arr, 4, 0, arr.size() - 1) << std::endl;
    return 0;
}