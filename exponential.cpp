#include <iostream>
#include <vector>

int binary_search(std::vector<int> array, int target, int start, int end) {
    if(target < array[start] && target > array[end]){
        return -1;
    }
    int mid = (start+end)/2;
    if (target == array[mid]) {
        return mid;
    } else if (target < array[mid]) {
        return binary_search(array, target, start, mid - 1);
    } else {
        return binary_search(array, target, mid + 1, end);
    }
    return -1;
}

int exponential_search(std::vector<int>& array, int target) {
    if (target < array[0] || target > array[array.size() - 1]) {
        return -1;
    }

    if (target == array[0]) {
        return 0;
    }

    int step = 1;

    while (step <= array.size() - 1) {
        if (target > array[step]) {
            step *= 2;
        } else if (target < array[step]) {
            return binary_search(array, target, step / 2, step - 1);
        } else if (target == array[step]) {
            return step;
        }
    }

    return binary_search(array, target, step / 2, array.size() - 1);
}

int main() {
    std::vector<int> array = {1, 4, 7, 10, 13};
    int target = 5;
    int result = exponential_search(array, target);

    if (result != -1) {
        std::cout << "The index of target: " << result << "\n";
    } else {
        std::cout << "The target not found in the array\n";
    }

    return 0;
}
