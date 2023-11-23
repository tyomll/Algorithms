#include <iostream>
#include <vector>

int main() {
    std::vector<int> array = {2, 7, 11, 15};
    int target = 9;

    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i] + array[j] == target) {
                std::cout << "[" << i << "," << j << "]" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "No two elements sum up to the target." << std::endl;
    return 0;
}
