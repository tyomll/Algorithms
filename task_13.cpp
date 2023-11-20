#include <iostream>

int divide(int array[], int low, int high) {
    int target = array[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (array[j] >= target) {
            std::swap(array[i + 1], array[j]);
            ++i;
        }
    }

    std::swap(array[i + 1], array[high]);

    return i + 1;
}

int largest(int array[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int divide_index = divide(array, low, high);

        if (divide_index - low == k - 1)
            return array[divide_index];

        if (divide_index - low > k - 1)
            return largest(array, low, divide_index - 1, k);

        return largest(array, divide_index + 1, high, k - divide_index + low - 1);
    }

    return -1;
}

int main() {
    int arr[] = {3, 1, 4, 4, 2, 2, 6};
    int k = 3;

    int result = largest(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, k);

    if (result == -1){
        std::cout << "Invalid value of k" << "\n";
        return 0;
    }

    std::cout << "The " << k << "th largest element is: " << result << "\n";
    
    return 0;
}
