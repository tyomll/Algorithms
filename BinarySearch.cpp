#include <iostream>
#include <vector>

int binary_search(std::vector<int>& arr, int target) {
    int index = arr.size() / 2;
    int start = 0;
    int end = arr.size() - 1;
    while (index >= start && index <= end) {
        if (arr[index] == target) {
            return index;
        }
        if (target < arr[index]) {
            end = index - 1;
            index = (start + end) / 2;
            continue;
        }
        if (target > arr[index]) {
            start = index + 1;
            index = (start + end) / 2;
            continue;
        }
    }
    return -1;
    
}

int main() {
    std::vector<int> arr = {2, 3, 9, 14, 23, 25, 42, 65, 99};
    int index = binary_search(arr, 23);
    std::cout << "Index = " << index << std::endl;
    return 0;
}