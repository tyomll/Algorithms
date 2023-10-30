#include <iostream>
#include <vector>
#include <map>

void matching_pairs(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::map<int, std::vector<int>> indices_map;

    for (int i = 0; i < arr1.size(); ++i) {
        indices_map[arr1[i]].push_back(i);
    }

    bool match_found = false;

    for (int j = 0; j < arr2.size(); ++j) {
        if (indices_map.find(arr2[j]) != indices_map.end()) {
            match_found = true;
            std::vector<int> indices = indices_map[arr2[j]];
            for (int k = 0; k < indices.size(); ++k) {
                std::cout << "(" << arr2[j] << ", " << arr1[indices[k]] << ")" << std::endl;
            }
        }
    }

    if (!match_found) {
        std::cout << "No matching pairs found." << std::endl;
    }
}

int main() {
    std::vector<int> arr1 = {5, 4, 2, 1, 3};
    std::vector<int> arr2 = {2, 1, 4, 3, 5};
    
    std::cout << "Matching pairs:" << std::endl;
    matching_pairs(arr1, arr2);

    return 0;
}

