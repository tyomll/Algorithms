#include <iostream>

void selection_sort (int array[], int size){
    int min_num;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(array[j] < array[i]){
                std::swap(array[j],array[i]);
            }
        }
    }
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
    std::cout << "Sorted array" << "\n";
    selection_sort(array,size);
    for(int i=0; i<size; i++){
        std::cout << array[i];
    }
    std::cout << "\n";
    return 0;
}