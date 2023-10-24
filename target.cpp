#include <iostream>

int* twoSum(int* nums, int length, int target) {
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (nums[i] + nums[j] == target) {
                static int result[2] = {i, j};
                return result;
            }
        }
    }
    return nullptr;
}

int main() {
    int* nums;
    int numCount, target;

    std::cout << "Enter the number of elements in the array: ";
    std::cin >> numCount;

    nums = new int[numCount];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < numCount; ++i) {
        std::cin >> nums[i];
    }

    std::cout << "Enter the target number: ";
    std::cin >> target;

    int* result = twoSum(nums, numCount, target);

    if (result != nullptr) {
        std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    } else {
        std::cout << "No two elements found in the array that add up to the target." << std::endl;
    }

    delete[] nums;

    return 0;
}

