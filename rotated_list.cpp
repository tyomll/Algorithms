#include <iostream>
#include <list>

void rotate_list(std::list<int>& num, int k) {

    int length = num.size();
    k = k % length;

    if (k == 0) return;

    for (int i = 0; i < k; ++i) {
        int last_element = num.back();
        num.pop_back();
        num.push_front(last_element);
    }
}

int main() {
    std::list<int> nums = {1, 2, 3, 4, 5};
    int k = 2;

    std::cout << "Original list: ";
    for (auto num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
   
    rotate_list(nums, k);

    std::cout << "Rotated list: ";
    for (auto num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

