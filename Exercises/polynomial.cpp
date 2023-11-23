#include <iostream>
#include <vector>
#include <string>

bool isPolynomial(int num) {
    std::string numStr = std::to_string(num);
    int length = numStr.length();

    for (int i = 0; i < length / 2; i++) {
        if (numStr[i] != numStr[length - 1 - i]) {
            return false;
        }
    }

    return true;
}

std::vector<int> findPolynomialElements(const std::vector<int>& inputArray) {
    std::vector<int> result;

    for (int num : inputArray) {
        if (isPolynomial(num)) {
            result.push_back(num);
        }
    }

    return result;
}

int main() {
    std::vector<int> inputArray = {121, 77, 89, 101, 977};
    std::vector<int> result = findPolynomialElements(inputArray);

    std::cout << "Polynomial elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

