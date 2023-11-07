#include <iostream>

void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int current = array[i];

        while (i-1 >= 0 && array[i-1] > current) {
            array[i] = array[i-1];
            i--;
        }
        array[i] = current;
    }
}

void shell(int array[], int size) {
    int gap = size/2;

    while(gap > 1){
    for(int i = 0; i < size - gap; ++i){
        if(array[i] > array[i+gap]){
            std::swap(array[i],array[i+gap]);
        }
        ++i;
    }
    gap = gap/2;
    }
    insertion_sort(array,size);
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
    shell(array, size);
    print_array(array, size);
    delete[] array;

    return 0;
}
