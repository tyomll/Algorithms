#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int FirstIndex) {
    int largest = FirstIndex;
    int leftChild = 2 * FirstIndex + 1;
    int rightChild = 2 * FirstIndex + 2;
    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }
    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }
    if (largest != FirstIndex) {
        std::swap(arr[FirstIndex], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(const std::vector<int>& arr) {
    for (const int& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    std::cout << "Original array: ";
    printArray(arr);
    heapSort(arr);
    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
