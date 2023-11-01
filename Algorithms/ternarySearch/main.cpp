#include <iostream>
#include <vector>

int ternarySearch(const std::vector<int>& arr, const int& target, int leftIndex,
                  int rightIndex) {
    if (target == arr[leftIndex]) {
        return leftIndex;
    }
    if (target == arr[rightIndex]) {
        return rightIndex;
    }
    if (target > arr[leftIndex] && target < arr[rightIndex]) {
        leftIndex++;
        return ternarySearch(arr, target, leftIndex, rightIndex);
    }
    if (target > arr[rightIndex]) {
        rightIndex++;
        return ternarySearch(arr, target, leftIndex, rightIndex);
    }
    if (target < arr[leftIndex]) {
        leftIndex--;
        return ternarySearch(arr, target, leftIndex, rightIndex);
    }

    return -1;
}

int ternarySearch(const std::vector<int>& arr, const int& target) {
    int rightIndex = arr.size() / 2;
    int leftIndex = rightIndex / 2;

    return ternarySearch(arr, target, leftIndex, rightIndex);
}

int main() {
    int target = 3;

    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    std::cout << ternarySearch(arr, target) << std::endl;

    return 0;
}