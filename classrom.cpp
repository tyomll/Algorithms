#include <iostream>
#include <vector>

void find(std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i; j < arr.size(); j++) {
            if (arr[i] + arr[j] == target)
                std::cout << "i : " << i << "\nj : " << j << std::endl;
        }
    }
}

int main() {
    std::vector<int> array;
    array.push_back(2);
    array.push_back(7);
    array.push_back(11);
    array.push_back(15);
    int target = 9;
    find(array, target);
    return 0;
}