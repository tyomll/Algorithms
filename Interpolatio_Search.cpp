#include <iostream>

int interpolation_search(int arr[], int end, int target) {
    
    int start = 0;
    
    while (start < end) {
    
    int pos = start + (((end - start) / (arr[end] - arr[start])) * (target - arr[start]));

        if (arr[pos] == target) {
            std::cout << pos << std::endl;
            return pos;
        }
        else if (arr[pos] < target) {
            start = pos + 1;
        }
        else {
            end = pos -1;
        }
    }
    
    return -1;
}

int main() {
    int arr[] = {4, 8, 12, 24, 26, 27, 32, 35, 37};
    int size = sizeof(arr) / sizeof(arr[0]);
    interpolation_search(arr, size, 26);
    return 0;
}