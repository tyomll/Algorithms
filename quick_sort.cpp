#include <iostream>
#include <vector>

void print_arr(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Array[" << i << "] = " << arr[i] << std::endl;
    }
}

std::vector<int> quick_sort(std::vector<int>& arr) {
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

    left = quick_sort(left);
    right = quick_sort(right);

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
    std::vector<int> arr = {5, 3, 18, 0, -6, 14, 1, -12, 9};
    std::vector<int> result = quick_sort(arr);
    std::cout << "Sorted array\n\n";
    print_arr(result);
    
    return 0;
}