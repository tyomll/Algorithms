#include <iostream>
#include <math.h>

int jump_search(int arr[], int size, int value) {
    int step = floor(sqrt(size));
    int index = 0;
    while (arr[index] < value) {
        index += step;
        if (index > size - 1) {
            index = size - 1;
        }
        
    }
    if (arr[index] == value) {
        std::cout << index << std::endl;
        return index;
    }
    for (int i = index; i > (index -= step); i--) {
        if (arr[i] == value) {
            std::cout << i << std::endl;
            return index;
        }
    }
    return -1;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0] + 1);
    jump_search (arr, size, 0);
    return 0;
}