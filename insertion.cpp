#include <iostream>

void sortInsertion(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int element = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > element) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = element;
    }
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
}

int main() {
    int arr[] = {1, 5, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    sortInsertion(arr, size);
    return 0;
}
