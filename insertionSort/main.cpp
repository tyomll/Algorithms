#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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