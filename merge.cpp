#include <iostream>

void merge(int array[], int left_array[], int left_size, int right_array[], int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left_array[i] < right_array[j]) {
            array[k] = left_array[i];
            ++i;
        } else {
            array[k] = right_array[j];
            ++j;
        }
        ++k;
    }

    while (i < left_size) {
        array[k] = left_array[i];
        ++i;
        ++k;
    }

    while (j < right_size) {
        array[k] = right_array[j];
        ++j;
        ++k;
    }
}

void merge_sort(int array[], int size) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;
    int left_array[mid];
    int right_array[size - mid];

    for (int i = 0; i < mid; ++i) {
        left_array[i] = array[i];
    }

    for (int i = mid; i < size; ++i) {
        right_array[i - mid] = array[i];
    }

    merge_sort(left_array, mid);
    merge_sort(right_array, size - mid);

    merge(array, left_array, mid, right_array, size - mid);
}

void enter_array(int size, int array[]) {
    std::cout << "Enter the array: " << "\n";
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
    int* array = new int[size];
    enter_array(size, array);
    std::cout <<"Sorted array is: ";
    merge_sort(array, size);
    print_array(array, size);
    delete[] array;

    return 0;
}
