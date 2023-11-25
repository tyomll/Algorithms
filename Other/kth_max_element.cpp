#include <iostream>
using namespace std;

int kth_max_element(int arr[], int size, int k) {
    if (size == 0 || k < 1 || k > size) {
        return -1; 
    }

    int pivot = arr[size / 2];
    int left[size], right[size], mid[size];
    int leftSize = 0, rightSize = 0, midSize = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > pivot) {
            left[leftSize++] = arr[i];
        } else if (arr[i] == pivot) {
            mid[midSize++] = arr[i];
        } else {
            right[rightSize++] = arr[i];
        }
    }

    if (k <= leftSize) {
        return kth_max_element(left, leftSize, k);
    } else if (k <= leftSize + midSize) {
        return pivot;
    } else {
        return kth_max_element(right, rightSize, k - leftSize - midSize);
    }
}

int main() {
    int arr[] = {1, 5, 3, 2, 2, 6, 2, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int result = kth_max_element(arr, size, k);

    if (result != -1) {
        cout << "The " << k << "th largest element is: " << result << endl;
    } else {
        cout << "Invalid input or k out of range." << endl;
    }

    return 0;
}
