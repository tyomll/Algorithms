#include <iostream>
#include <vector>

void makeHeap(std::vector<int>& array) {
    bool condition = true;
    while (condition) {
        condition = false;
        int index = array.size() - 1;
        while (index >= 0) {
            if (array[index] < array[(index - 1) / 2]) {
                std::swap(array[index], array[(index - 1) / 2]);
                condition = true;
            }
            --index;
        }
    }
    
}

std::vector<int> sortHeap(std::vector<int>& array) {
    std::vector<int> result;
    int index = 0;
    int arraySize = array.size();
    while (index < arraySize) {
        result.push_back(array[0]);
        std::swap(array[0], array[array.size() - 1]);
        array.pop_back();
        makeHeap(array);
        ++index;
    }

    return result;
}

void printArr(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Array[" << i << "] = " << arr[i] << std::endl;
    }
}

int main() {
    std::vector<int> arr = {3, 2, 4, 1, 5, 9};
    std::vector<int> sortArray;
    std::cout << "First array\n";
    printArr(arr);
    std::cout << "\nMake heap\n\n";
    makeHeap(arr);
    printArr(arr);
    std::cout << "\nSort heap\n\n";
    sortArray = sortHeap(arr);
    printArr(sortArray);
    return 0;
}