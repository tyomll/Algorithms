#include <iostream>
#include <vector>

int interpolation(std::vector<int> array, int target, int low, int high){
    
    if (target < array[0] || target > array[array.size() - 1]) {
        return -1;
    }

    int pos = low +(target - array[low])*(high - low)/(array[high] - array[low]);

    if(target > array[pos]){
        return interpolation(array, target, pos+1, high);
    }

    if(target < array[pos]){
        return interpolation(array, target, low, pos-1);
    }
    return pos;
}

int main() {
    std::vector<int> array = {10, 20, 30, 40, 50};
    int target = 50;
    int index = interpolation(array, target, 0, array.size() - 1);

    if (index == -1) {
        std::cout << "Target not found!\n";
    } else {
        std::cout << "Index of " << target << " is: " << index << "\n";
    }

    return 0;
}
