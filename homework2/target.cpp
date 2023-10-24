#include <iostream>
#include <vector>
#include <unordered_map>

void find(std::vector<int>& arr, int target) {
    std::unordered_map<int, int> numToIndex;
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];

        if (numToIndex.find(complement) != numToIndex.end()) {
            std::cout << "i: " << numToIndex[complement] << "\nj: " << i << std::endl;
        }
        numToIndex[arr[i]] = i;
    }
}


int main() {
    std::vector<int> array;
    array.push_back(2);
    array.push_back(11);
    array.push_back(7);
    array.push_back(15);
    int target = 9;
    find(array, target);
    return 0;
}