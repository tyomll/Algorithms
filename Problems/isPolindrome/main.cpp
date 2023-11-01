#include <iostream>
#include <vector>

std::vector<int> isPolindrome(std::vector<int> arr) {
    std::vector<int> polindromes;
    std::vector<std::string> stringArr;

    for (size_t i = 0; i < arr.size(); i++) {
        stringArr.push_back(std::to_string(arr[i]));
    }

    for (size_t i = 0; i < stringArr.size(); i++) {
        int stringLength = stringArr[i].length();
        bool isPol = true;

        for (size_t j = 0; j < stringLength / 2; j++) {
            if (stringArr[i][j] != stringArr[i][stringLength - 1 - j]) {
                isPol = false;
            }
        }
        if (isPol) {
            polindromes.push_back(arr[i]);
        }
    }

    return polindromes;
}

int main() {
    std::vector<int> arr = {37, 77, 89, 100, 979};
    std::vector<int> polindromes = isPolindrome(arr);

    for (const int& el : polindromes) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;
    return 0;
}