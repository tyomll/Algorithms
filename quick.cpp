#include <iostream>
#include <vector>

void quick(std::vector<int>& array){
    int size = array.size();
    if (size <= 1) {
        return;
    };
    int mid = size/2;
    int pivot = array[mid];
    std::vector<int> left_array,right_array;

    for(int i = 0; i < size; ++i){
        if (i == mid) {
            continue;
        }
        if(array[i] < pivot){
            left_array.push_back(array[i]);
        }
        else {
            right_array.push_back(array[i]);            
        }
    }

    quick(left_array);
    quick(right_array);

    array=left_array;
    array.push_back(pivot);
    for(int i=0; i < right_array.size(); ++i ){
        array.push_back(right_array[i]);
    }
}
void enter_array(std::vector<int>& array) {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    array.resize(size);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
}

void print_array(const std::vector<int>& array) {
    for (int i = 0; i< array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> array = {5, 2, 9, 3, 6, 1};
    enter_array(array);
    quick(array);
    std::cout << "Sorted array: ";
    print_array(array);

    return 0;
}