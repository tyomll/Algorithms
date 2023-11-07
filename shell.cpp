#include <iostream>

void insertion_sort(int array[], int n) {
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

void shell_sort(int array[], int size){
    int gap = size/2;
    while(gap >= 1){
        for(int i=0; i<size-gap; i++){
            if(array[i] > array[i+gap]){
                 std::swap(array[i],array[i+gap]);
            }

        }
        gap /= 2;
    }
    insertion_sort(array,size);
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
    enter_array(array, size);

    shell_sort(array,size);
    std::cout << "Sorted array" << "\n";
    print_array(array,size);

    std::cout << "\n";
    delete[] array;
    return 0;
}