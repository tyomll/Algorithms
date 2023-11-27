#include <iostream>
#include <vector>

int findMaxElement(std::vector<int> vec, int k) {
    int maxIndex = 0, maxElement;
    for (int i = 0; i < k; ++i) {
        maxElement = vec[0];
        for (int j = 1; j < vec.size(); ++j) {
            if (vec[j] > maxElement) {
                maxIndex = j;
                maxElement = vec[j];
            }
        }
        vec.erase(vec.begin() + maxIndex);
        maxIndex = 0;
    }

    return maxElement;
}

int main() {
    std::vector<int> vec = {3, 2, 1, 5, 6, 4};
    std::cout << findMaxElement(vec, 2) << std::endl;

    return 0;
}