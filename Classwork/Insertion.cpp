#include <iostream>

void printArr(int* arr, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "Array[" << i << "] = " << arr[i] << std::endl;
    }
}

void insertArr(int* arr, int count) {
    for (int i = 0; i < count; i++) {
        std::cout << "Array[" << i << "] = ";
        std::cin >> arr[i];
    }
}

void insertionSort(int* arr, int count) {
    for (int i = 1; i < count; ++i) { 
        while (arr[i] < arr[i - 1] && i >= 1) {
            std::swap(arr[i], arr[i - 1]);
            --i;
        }
    }
}

int main() {
    int count;
    std::cout << "Count = ";
    std::cin >> count;
    int arr[count];
    insertArr(arr, count);
    insertionSort(arr, count);
    std::cout << "\nSorted\n\n";
    printArr(arr, count);

    return 0;
}