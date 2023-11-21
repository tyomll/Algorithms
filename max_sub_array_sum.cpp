#include <iostream>
#include <vector>

std::pair<int, std::pair<int, int>> array_sum(std::vector<int>& nums) {
   
    int max_sum = nums[0];
    int current_sum = nums[0];
    int start = 0;
    int end = 0;
    int temp_start = 0;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > current_sum + nums[i]) {
            current_sum = nums[i];
            temp_start = i;
        } else {
            current_sum = current_sum + nums[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }

    return {max_sum, {start, end}};
}

int main() {
    std::vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto result = array_sum(arr1);
    std::cout << "Maximum subarray sum: " << result.first << std::endl;
    std::cout << "Subarray elements: ";
    for (int i = result.second.first; i <= result.second.second; ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

