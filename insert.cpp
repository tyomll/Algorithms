#include <iostream>

void sort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {
    int arr[] = {7, 9, 1, 17};
    int arr_size = 4;
    
    std::cout << "Original array: ";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    sort(arr, arr_size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}