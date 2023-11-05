#include <iostream>
#include <vector>

void printArr(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Array[" << i << "] = " << arr[i] << std::endl;
    }
}

std::vector<int> quickSort(std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    std::vector<int> left, right, result;
    int mid = arr.size() / 2;
    int pivot = arr[mid];

    for (auto element : arr) {
        if (element == arr[mid]) {
            continue;
        }
        if (element < arr[mid]) {
            left.push_back(element);
        }
        else {
            right.push_back(element);
        }
    }

    left = quickSort(left);
    right = quickSort(right);

    for (auto element : left) {
        result.push_back(element);
    }

    result.push_back(pivot);

    for (auto element : right) {
        result.push_back(element);
    }
    return result;
}

int main() {
    std::vector<int> arr = {48, -9, 25, 0, 36, 98, -58, -147, 3};
    std::vector<int> result = quickSort(arr);
    std::cout << "Sorted array\n\n";
    printArr(result);
    
    return 0;
}