#include <iostream>
#include <vector>

int find_k_max(std::vector<int>& num, int k) {
    int max = 0;

    for (std::vector<int>::size_type i = 0; i < num.size(); ++i) {
        int count = 0;
        for (std::vector<int>::size_type j = 0; j < num.size(); ++j) {
            if (num[j] > num[i]) {
                count++;
            }
        }
        if (count == k - 1) {
            max = num[i];
            break;
        }
    }

    return max;
}

int main() {
    std::vector<int> num = {3, 2, 1, 5, 6, 4};
    int k = 2;

    int result = find_k_max(num, k);
    std::cout << "The " << k << "-th largest element is: " << result << std::endl;

    return 0;
}

