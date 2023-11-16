#include <iostream>
#include <limits>
#include <vector>

int findLongestSubarraySum(const std::vector<int>& nums) {
    int sum = std::numeric_limits<int>::min();
    int currentSum = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        currentSum += nums[i];

        if (currentSum > sum) {
            sum = currentSum;
        }

        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return sum;
}

int main() {
    std::vector<int> nums = {-2, 1, 0, -1, 2, 1, -5, 4};

    std::cout << findLongestSubarraySum(nums) << std::endl;
    return 0;
}