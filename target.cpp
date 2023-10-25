#include <iostream>
#include <vector>

void sum(const std::vector<int>& array, int target) {
    for (int i = 0; i < array.size(); i++) {
        int element1 = array[i];
        int element2 = target - element1;

        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] == element2) {
                std::cout << "[" << i << ";" << j << "]" << "\n";
                return; 
            }
        }
    }

}

int main() {
    std::vector<int> array = {2, 11, 15, 7};
    int targetSum = 9;

    sum(array, targetSum);

    return 0;
}
