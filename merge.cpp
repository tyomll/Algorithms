#include <iostream>

void merge(int L[], int left_size, int R[], int right_size, int sorted[]) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (L[i] < R[j]) {
            sorted[k] = L[i];
            ++k;
            ++i;
        } else {
            sorted[k] = R[j];
            ++k;
            ++j;
        }
    }

    while (i < left_size) {
        sorted[k] = L[i];
        ++k;
        ++i;
    }

    while (j < right_size) {
        sorted[k] = R[j];
        ++k;
        ++j;
    }
}

void merge_sort(int array[], int size) {
    if (size == 1) {
        return;
    }

    int mid = size / 2;
    int left_arr[mid];
    int right_arr[size - mid];

    for (int i = 0; i < mid; i++) {
        left_arr[i] = array[i];
    }

    for (int j = mid; j < size; j++) {
        right_arr[j - mid] = array[j];
    }

    merge_sort(left_arr, mid);
    merge_sort(right_arr, size - mid);

    merge(left_arr, mid, right_arr, size - mid, array);
}
void enter_array(int array[], int size) {
    std::cout << "Enter the array" << "\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int size;
    std::cout << "Enter the size: ";
    std::cin >> size;
    int *array = new int[size];
    enter_array(array,size);

    std::cout << "Original array: ";
    print_array(array, size);
    merge_sort(array, size);

    std::cout << "Sorted array: ";
    print_array(array,size);

    delete[] array;
    return 0;
}
