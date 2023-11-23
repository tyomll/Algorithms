#include <iostream>

int interpolationSearch(int arr[], int low, int high, int x) {
    int pos;
    if (low <= high && x >= arr[low] && x <= arr[high]) {
        pos = low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, high, x);

        if (arr[pos] > x)
            return interpolationSearch(arr, low, pos - 1, x);
    }
    return -1;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    
    if (n <= 0) {
        std::cout << "The array size must be greater than 0.";
        return 1;
    }
    
    int arr[n];

    std::cout << "Enter the elements of the array separated by spaces (e.g., 1 2 3 4): ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int x;
    std::cout << "Enter the number you want to search: ";
    std::cin >> x;

    int index = interpolationSearch(arr, 0, n - 1, x);

    if (index != -1)
        std::cout << "Element found at index " << index;
    else
        std::cout << "Element not found.";
    return 0;
}

