#include <iostream>
#include <vector>

int sum(const std::vector<int>& array) {
    if (array.empty()) {
        return 0;
    }
    int  max_end = array[0];
    int current_max = array[0];
    for (int i = 1; i < array.size(); ++i) {
        if (array[i] > max_end + array[i]) {
            max_end = array[i];
        } else {
            max_end += array[i];
        }
        if (max_end > current_max) {
           current_max = max_end;
        }
    }
    return current_max;
}

int main() {
    std::vector<int> example1 = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << "Example 1: " << sum(example1) << "\n";
    std::vector<int> example2 = {5,4,-1,7,8};
    std::cout << "Example 2: " << sum(example2) << "\n";
    
    return 0;
}