#include <iostream>

int divide(int array[], int left, int right) {
    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (array[j] >= pivot) {
            std::swap(array[i + 1], array[j]);
            ++i;
        }
    }
    std::swap(array[i + 1], array[right]);
    return i + 1;
}

int k_largest_element(int array[], int left, int right, int k) {
    if (k > 0 && k <= right - left + 1) {
        int divide_index = divide(array, left, right);

        if (divide_index - left == k - 1)
            return array[divide_index];

        if (divide_index - left > k - 1)
            return k_largest_element(array, left, divide_index - 1, k);

        return k_largest_element(array, divide_index + 1, right, k - divide_index + left - 1);
    }

    return -1;
}

int main() {
    int array[] = {3, 2, 1, 5, 6, 4};
    int k = 3;
    int result = k_largest_element(array, 0, sizeof(array) / sizeof(array[0]) - 1, k);
    std::cout << "The " << k << "th largest element is: " << result << "\n";

    return 0;
}