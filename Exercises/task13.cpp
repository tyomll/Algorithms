#include <iostream>
#include <vector>

int findMaxElement(std::vector<int> array, int k) {
    int maxIndex = 0, maxElement;
    for (int i = 0; i < k; ++i) {
        maxElement = array[0];
        for (int j = 1; j < array.size(); ++j) {
            if (array[j] > maxElement) {
                maxIndex = j;
                maxElement = array[j];
            }
        }
        array.erase(array.begin() + maxIndex);
        maxIndex = 0;
    }

    return maxElement;
}

int main() {
    std::vector<int> array = {6, 3, 9, 1, 4, 3, 2};
    std::cout << findMaxElement(array, 2) << std::endl;

    return 0;
}