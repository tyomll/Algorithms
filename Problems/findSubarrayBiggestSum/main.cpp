#include <iostream>
#include <limits>
#include <vector>

std::vector<int> findSubarrayWithBiggestSum(const std::vector<int>& nums) {
    int sum = std::numeric_limits<int>::min();
    std::vector<int> currentSubarray;
    std::vector<int> subarray;
    int currentSum = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        currentSum += nums[i];
        currentSubarray.push_back(nums[i]);

        if (currentSum > sum) {
            sum = currentSum;
            subarray = currentSubarray;
        }

        if (currentSum < 0) {
            currentSum = 0;
            currentSubarray.clear();
        }
    }

    return subarray;
}

int main() {
    std::vector<int> nums = {5, 4, -1, 7, 8};

    for (const int& el : findSubarrayWithBiggestSum(nums)) {
        std::cout << el << " ";
    }
    return 0;
}