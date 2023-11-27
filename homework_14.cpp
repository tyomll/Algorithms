#include <iostream>
#include <vector>
#include <climits>

std::vector<int> maxSubarray(const std::vector<int>& nums) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    int start = 0;
    int end = 0;
    int temp_start = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > current_sum + nums[i]) {
            current_sum = nums[i];
            temp_start = i;
        } else {
            current_sum += nums[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }

    return std::vector<int>(nums.begin() + start, nums.begin() + end + 1);
}

int main() {
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int> result = maxSubarray(nums);

    std::cout << "Subarray with the largest sum: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}