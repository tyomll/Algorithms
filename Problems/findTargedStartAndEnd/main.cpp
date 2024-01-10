#include <iostream>
#include <vector>

std::vector<int> findTargetStartAndEnd(const std::vector<int>& arr,
                                       const int& target) {
    int middle = arr.size() / 2;
    std::vector<int> indexes;

    while (middle < arr.size() && middle >= 0) {
        if (arr[middle] == target && arr[middle + 1] != target) {
            indexes.push_back(middle);
            break;
        }
        if (arr[middle] == target && arr[middle - 1] != target) {
            indexes.push_back(middle);
            middle++;
        }
        if (arr[middle] > target) {
            middle++;
        }
        if (arr[middle] < target) {
            middle--;
        }
    }

    if (indexes.size() == 0) {
        for (size_t i = 0; i < 2; i++) {
            indexes.push_back(-1);
        }
    }
    return indexes;
}

int main() {
    int target = 8;
    std::vector<int> arr = {5, 7, 7, 8, 8, 10};

    std::vector<int> firstAndLastIndexes = findTargetStartAndEnd(arr, target);

    for (const int& el : firstAndLastIndexes) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}