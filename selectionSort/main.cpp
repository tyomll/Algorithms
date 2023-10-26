#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        int min = arr[i];
        int minIndex = i;

        for (size_t j = i + 1; j < arr.size(); j++) {
            if (min > arr[j]) {
                min = arr[j];
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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
    std::vector arr = inputArr();
    selectionSort(arr);

    for (const int& el : arr) {
        std::cout << el << ",";
    }
    std::cout << std::endl;
    return 0;
}