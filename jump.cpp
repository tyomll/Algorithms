#include <iostream>
#include <vector>
#include <cmath>

int binary(std::vector<int> array, int target, int start, int end){
    
    if (target < array[0] || target > array[array.size() - 1]){
        return -1;
    }
     
    int mid = (start + end) / 2;

    if (target < array[mid]){
        return binary(array, target, start, mid - 1);
    }

    if (target > array[mid]){
        return binary(array, target, mid + 1, end);
    }

    return mid; 
}

int jump(std::vector<int> array, int target, int start, int end) {
    if (target < array[0] || target > array[array.size() - 1]) {
        return -1;
    }

    if (target == array[0]) {
        return 0;
    }

    int step = sqrt(array.size()-1);

    while(step < array.size()){
        
        if(target > array[step]){
            step += sqrt(array.size()-1);
        }
        
        if (target < array[step]){
            return binary(array, target, step-sqrt(array.size()-1), step-1);
        }
        
        if (target == array[step]){
            return step;
        }
    }

    return binary(array, target, step-sqrt(array.size()-1), array.size() - 1);

}

int main() {
    std::vector<int> array = {1, 2, 3, 4, 5};
    int target = 5;
    int index = jump(array, target, 0, array.size() - 1);

    if (index == -1) {
        std::cout << "Target not found!\n";
    } else {
        std::cout << "Index of " << target << " is: " << index << "\n";
    }

    return 0;
}
