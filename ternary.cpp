#include <iostream>

int ternarySearch(int arr[], int target, int left, int rigth){
    int mid1  = left + (rigth - left) / 3;
    int mid2 = left + 2 * (rigth - left) / 3;
    if (arr[mid1] == target) {
        return mid1;
    }

    else if (arr[mid2] == target) {
        return mid2;
    }

    else if (arr[mid1] > target){
        return ternarySearch(arr, target, left, mid1 - 1);
    }
    
    else if (arr[mid2] < target) {
        return ternarySearch(arr, target, mid2 - 1, rigth);
    }

    else if (arr[mid1] < target < arr[mid2]){
        return ternarySearch(arr, target, mid1 + 1, mid2 - 1);
    }
    
    return -1;

    
}

int main () {
    int arr[] = {1, 3, 5, 8, 20, 30, 40};
    int target = 8;
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << ternarySearch(arr, target, 0, size  - 1) << std::endl;
    return 0;
}


