#include <iostream>

int binarySearch(int arr[], int target, int left, int rigth){
    int mid = left + (rigth - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    else if (arr[mid] < target) {
        return binarySearch(arr, target, mid + 1, rigth);
    }
    else if (arr[mid] > target) {
        return binarySearch(arr, target, left, mid - 1);
    }
    return -1;
}

int main() {
    int arr[] = {1, 5, 7, 9, 12, 16, 36};
    int target = 36; 
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << binarySearch(arr, target, 0, size) << std::endl;
    return 0;
}
