#include <iostream>
#include <vector>

int max_sum(std::vector<int>& array) {
    if (array.empty()) {
        return 0;
    }

    int max_end = array[0];
    int current_max = array[0];

    for (int i = 1; i < array.size(); ++i) {
        if (array[i] > max_end + array[i]) {
            max_end = array[i];
        } else {
            max_end = max_end + array[i];
        }

        if (max_end > current_max) {
            current_max = max_end;
        }
    }

    return current_max;
}

int main() {

    std::vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Sum is: " << max_sum(array) << "\n";

    return 0;
}
