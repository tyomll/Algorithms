#include <iostream>

void selection(int array[], int size){
    
    for(int i=0; i < size; ++i){
        for(int j=i+1; j< size; ++j){
            if (array[j] < array[i]){
                std::swap(array[j], array[i]);
            }
        }
    }

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

int main(){
    int size;
    std::cout << "Enter the size: ";
    std::cin >> size;
    int* array = new int[size];
    enter_array(size, array);
    std::cout <<"Sorted array is: ";
    selection(array, size);
    print_array(array, size);

    return 0;
}