#include <iostream>
#include <vector>

using namespace std;

class SubsequenceResult {
	public:
		int maxSum;
		int startIndex;
		int endIndex;
};

SubsequenceResult findMaxSubsequenceSum(const vector<int>& nums) {
	int n = nums.size();
	int maxSum = nums[0];
	int currentSum = nums[0];
	int start = 0;
	int end = 0;
	int tempStart = 0;

	for (int i = 1; i < n; ++i) {
		if (currentSum < 0) {
			currentSum = nums[i];
			tempStart = i;
		}

		else {
			currentSum += nums[i];
		}

		if (currentSum > maxSum) {
			maxSum = currentSum;
			start = tempStart;
			end = i;
		}
	}

	SubsequenceResult result;
	result.maxSum = maxSum;
	result.startIndex = start;
	result.endIndex = end;

	return result;
}

int main() {
	vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

	SubsequenceResult result = findMaxSubsequenceSum(nums);

	cout << "The array [ ";
	for (int i = result.startIndex; i < result.endIndex + 1; i++){
		cout << nums[i] << ", ";
	}
	cout << "] ";

	cout << "has the largest sum " << result.maxSum << endl;

	return 0;
}

