#include <iostream>
#include <vector>

void quickSort(std::vector<int>& array){
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

    quickSort(left_array);
    quickSort(right_array);

    array=left_array;
    array.push_back(pivot);
    for(int i=0; i < right_array.size(); ++i ){
        array.push_back(right_array[i]);
    }
}


void print(const std::vector<int>& array) {
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> array = { 3, 0, 6, 7, 2, 9};
    std::cout << "Original arrey: ";
    print(array);
    quickSort(array);
    std::cout << "Sorted array: ";
    print(array);

    return 0;
}