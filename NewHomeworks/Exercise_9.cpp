#include <iostream>
#include <vector>

using namespace std;

int max_subarray_sum(const vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int max_ending_here = nums[0];
    int max_so_far = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        max_ending_here = max(nums[i], max_ending_here + nums[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main() {
    // Example 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result1 = max_subarray_sum(nums1);
    cout << "Example 1: " << result1 << endl;

    // Example 2
    vector<int> nums2 = {1};
    int result2 = max_subarray_sum(nums2);
    cout << "Example 2: " << result2 << endl;

    return 0;
}
