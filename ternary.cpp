#include <iostream> 
#include <vector>

int ternary (std::vector<int> array, int target, int start, int end) {
    
    if (target < array[0] || target > array[array.size() - 1]){
        return -1;
    }

    int mid1 = start + (end - start) / 3;
    int mid2 = start + 2 * (end - start) / 3;

    if ( target == array[mid1]) {
        return mid1;
    }

    if ( target == array[mid2]) {
        return mid2;
    }

    if (target < array[mid1]) {
        return (array, target, start, mid1 - 1);
    }

    if (target > array[mid2]) {
        return (array, target, mid2 + 1, end);
    }


    return (array, target, mid1 + 1, mid2 -1);

}

int main() {
    std::vector<int> array = { 1, 2, 3, 4, 5};
    int  target = 5;
    int index =  ternary(array, target, 0, array.size() - 1);
    
    if (index == -1) {
        std::cout << "Target not found!\n";
        return 0;
    } 

    std::cout << "Index of " << target << " is: " << index << "\n";
    return 0;
}