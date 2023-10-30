#include <iostream>
#include <map>
#include <vector>

void matching_pairs(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::map<int, int> pair_map;

    for (int i = 0; i < arr1.size(); i++) {
        pair_map[arr1[i]] = i;
    }

    std::cout << "Matching pairs found: ";
    bool found = false;

    for (int i = 0; i < arr2.size(); i++) {
        int element = arr2[i];
        if (pair_map.find(element) != pair_map.end()) {
            if (found) {
                std::cout << ", ";
            }
            int index = pair_map[element];
            std::cout << "(" << arr1[index] << ", " << element << ")";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching pairs found.";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> arr1 = {5, 4, 2, 1, 3};
    std::vector<int> arr2 = {3, 1, 4, 2, 5};

    matching_pairs(arr1, arr2);

    return 0;
}
