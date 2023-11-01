#include <iostream>
#include <vector>

int search(std::vector<int>& array, int target) {
    int index = array.size() / 2;
    int start = 0;
    int end = array.size() - 1;
    while (index >= start && index <= end) {
        if (array[index] == target) {
            return index;
        }
        if (target < array[index]) {
            end = index - 1;
            index = (start + end) / 2;
            std::cout << array[index] << std::endl;
            continue;
        }
        if (target > array[index]) {
            start = index + 1;
            index = (start + end) / 2;
            std::cout << array[index] << std::endl;
            continue;
        }
    }
    return -1;
    
}

int main() {
    std::vector<int> arr = {1, 5, 7, 8, 18, 25, 36, 100, 110};
    int index = search(arr, 550);
    std::cout << "Index = " << index << std::endl;
    return 0;
}