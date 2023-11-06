#include <iostream>
#include <vector>

int ternary_search(const std::vector<int>& arr, int target, int start, int end) {
    if (start <= end) {
        int middenLeft = start + (end - start) / 3;
        int middenRight = start + 2 * (end - start) / 3;

        if (arr[middenLeft] == target) {
            return middenLeft;
        }
        if (arr[middenRight] == target) {
            return middenRight;
        }
        if (target < arr[middenLeft]) {
            return ternary_search(arr, target, start, middenLeft - 1);
        } 
        else if (target > arr[middenRight]) {
            return ternary_search(arr, target, middenRight + 1, end);
        } 
        else {
            return ternary_search(arr, target, middenLeft + 1, middenRight - 1);
        }
    }

    return -1;
}

int main() {
    std::vector<int> arr = {1, 5, 7, 8, 18, 25, 36, 100, 110};
    int index = ternary_search(arr, 110, 0, arr.size() - 1);
    std::cout << "Index = " << index << std::endl;
    return 0;
}