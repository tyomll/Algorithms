#include <iostream>
#include <vector>

int binary_search(int arr[], int target, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (target < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}

int exponential_search(std::vector<int>& arr, int target, int size) {
    if (arr[0] == target) {
        return 0;
    }

    int i = 1;
    while (i < size && arr[i] <= target) {
        i *= 2;
    }

    return binary_search(arr.data(), target, i / 2, std::min(i, size - 1));
}

int main() {
    std::vector<int> arr = {2, 3, 9, 14, 23, 25, 42, 65, 99};
    int index = binary_search(arr.data(), 23, 0, arr.size() - 1);
    std::cout << "Index = " << index << std::endl;

    int exp_index = exponential_search(arr, 65, arr.size());
    std::cout << "Exponential Search Index = " << exp_index << std::endl;

    return 0;
}
