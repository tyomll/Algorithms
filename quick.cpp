#include <iostream>
#include <vector>

void quick_sort(std::vector<int>& array) {
    int size = array.size();

    if (size <= 1) {
        return;
    }

    int mid_index = size / 2;
    int pivot = array[mid_index];
    std::vector<int> left;
    std::vector<int> right;

    for (int i = 0; i < size; i++) {
        if (i == mid_index) {
            continue; 
        }

        if (array[i] < pivot) {
            left.push_back(array[i]);
        } else {
            right.push_back(array[i]);
        }
    }

    quick_sort(left);
    quick_sort(right);

    array=left;
    array.push_back(pivot);
    for(int i=0; i < right.size(); ++i ){
        array.push_back(right[i]);
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
    for (int i=0; i< array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> array;
    enter_array(array);
    std::cout << "Original array: ";
    print_array(array);
    quick_sort(array);

    std::cout << "Sorted array: ";
    print_array(array);

    return 0;
}
