#include <iostream>
#include <vector>

void printArr(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Array[" << i << "] = " << arr[i] << std::endl;
    }
}

void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) { 
        while (arr[i] < arr[i - 1] && i >= 1) {
            std::swap(arr[i], arr[i - 1]);
            --i;
        }
    }
}

void shellSort(std::vector<int>& array) {
    int step = array.size() / 2;
    while (step >= 1) {
        for (int i = 0; i < array.size() - step; ++i) {
            if (array[i] > array[i + step]) {
                std::swap(array[i], array[i + step]);
            }
        }
        step /= 2;
    }

    insertionSort(array);
}

int main() {
    std::vector<int> arr = {128, 10, 2, -5, 0, -8, 3, 5, 27, -10};
    std::cout << "First array\n";
    printArr(arr);
    std::cout << "\nSorted array\n\n";
    shellSort(arr);
    printArr(arr);
    return 0;
}