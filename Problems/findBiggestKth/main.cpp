#include <iostream>
#include <vector>

int findBiggestKth(const std::vector<int> nums, const int& k) {}

int main() {
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    std::cout << findBiggestKth(nums, k) << std::endl;
    return 0;
}

// stack - [2,3]

// if (hajord < stack.top &&  stack.size != k)
// stack.push(hajord)

// if(hajord > stack.top() && stack.size <= k )
// temp = stack.top
// stack.pop
// stack.push(hajord)
// stack.push(temp)