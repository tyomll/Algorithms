#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> finder(std::vector<int>& arr, int target) {
    std::unordered_map<int, int> indexes;
    std::vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        int target2 = target - arr[i];
        if (indexes.find(target2) != indexes.end()) {
            result.push_back(indexes[target2]);
            result.push_back(i);
            return result;
        }
        indexes[arr[i]] = i;
    }
    return result;
}

int main() {
    std::vector<int> arr;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        arr.push_back(elem);
    }

    int target;
	std::cout << "enter the target: ";
	std::cin >> target;
    std::vector<int> result = finder(arr, target);

    if (result.size() == 2) {
        std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    }
	else {
        std::cout << "No solution." << std::endl;
    }

    return 0;
}

