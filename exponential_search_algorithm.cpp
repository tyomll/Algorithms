#include <iostream>
#include <vector>

int exponentialSearch(std::vector<int>& arr, int x) {
    int n = arr.size();

    if (n == 0)
        return -1;

    int i = 1;
    while (i < n && arr[i] < x)
        i *= 2;

    int left = i / 2;
    int right = std::min(i, n - 1);

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int result = exponentialSearch(arr, x);

    if (result == -1) {
        std::cout << "Element not found in the array";
    } else {
        std::cout << "Element is present at index " << result << std::endl;
    }

    return 0;
}

