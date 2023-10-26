#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && current < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

std::vector<int> inputArr() {
    int size = 0;
    std::cout << "Enter the size of array: ";
    std::cin >> size;

    std::vector<int> arr;

    for (size_t i = 0; i < size; i++) {
        int value;
        std::cout << "Enter element[" << i << "]" << std::endl;
        std::cin >> value;
        arr.push_back(value);
    }
    return arr;
}

int main() {
    std::vector<int> arr = inputArr();
    insertionSort(arr);

    for (const int& el : arr) {
        std::cout << el << ",";
    }
    std::cout << std::endl;
    return 0;
}