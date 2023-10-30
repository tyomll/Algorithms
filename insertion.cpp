#include <iostream>

void print_array(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void insertion_sort(int arr[], int arr_size) {
    for (int i = 1; i < arr_size; i++) {
        int current = arr[i];

        while (i-1 >= 0 && arr[i-1] > current) {
            arr[i] = arr[i-1];
            i--;
        }
        arr[i] = current;
    }
}

int main() {
    int arr[] = {5, 1, 2, 3, 4};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    std::cout << "Original array: ";
    print_array(arr, arr_size);

    insertion_sort(arr, arr_size);

    std::cout << "Sorted array: ";
    print_array(arr, arr_size);

    return 0;
}
