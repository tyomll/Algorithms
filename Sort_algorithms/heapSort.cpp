#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void print(std::vector<int>& arr){
     for (int num : arr) {
        std:: cout << num << " ";
     }
     std:: cout << std::endl;
}

int main() {
    std::vector<int> arr = {1, 12, 4, 13, 8, 6};

    std::cout << "Original array: ";
    print(arr);
    
    heapSort(arr);

    std::cout << "Sorted array: ";
    print(arr);

    return 0;
}
