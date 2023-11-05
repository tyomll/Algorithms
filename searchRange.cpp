#include <iostream>
#include <vector>

std::vector<int> searchRange(const std::vector<int>& nums, int target, int left, int right) {
	if (left > right) {
		return {-1, -1};
	}
	int mid = left + (right - left) / 2;
	if (nums[mid] == target) {
		int start = mid;
		int end = mid;

		while (start > left && nums[start - 1] == target) {
			start--;
		}

		while (end < right && nums[end + 1] == target) {
			end++;
		}
		return {start, end};
	}
	else if (nums[mid] < target) {
		return searchRange(nums, target, mid + 1, right);
	}
	else {
		return searchRange(nums, target, left, mid - 1);
	}
}

std::vector<int> searchRange(const std::vector<int>& nums, int target) {
	return searchRange(nums, target, 0, nums.size() - 1);
}

int main() {
	std::vector<int> nums = {5, 7, 7, 8, 8, 10};
	int target = 7;

	std::vector<int> result = searchRange(nums, target);

	std::cout << "["  << result[0] << ", " << result[1] << "]" << std::endl;

	return 0;
}

