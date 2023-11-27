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

int vectorElementsSum(std::vector<int> vector) {
    int sum = 0;
    for (int element : vector) {
        sum += element;
    }

    return sum;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = vectorElementsSum(maxSubarray(nums));

    std::cout << "Sum: " << result << std::endl;

    return 0;
}