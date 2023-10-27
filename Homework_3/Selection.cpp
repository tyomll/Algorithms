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

void selectionSort(int* arr, int count) {
    int temp;
    for (int i = 0; i < count - 1; ++i) {
        temp = i;
        for (int j = i + 1; j < count; ++j) {
            if (arr[temp] > arr[j]) {
                temp = j;
            }
        }
        if (temp != i) {
            std::swap(arr[i], arr[temp]);
        }
    }
}

int main() {
    int count;
    std::cout << "Count = ";
    std::cin >> count;
    int arr[count];
    insertArr(arr, count);
    selectionSort(arr, count);
    std::cout << "\nSorted\n\n";
    printArr(arr, count);

    return 0;
}