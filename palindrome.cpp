#include <iostream>
#include <vector>

bool check(int num) {

    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }

    return originalNum == reversedNum;
}

std::vector<int> find(const std::vector<int>& array) {
    std::vector<int> palindromes;
    for (int num : array) {
        if (check(num)) {
            palindromes.push_back(num);
        }
    }
    return palindromes;
}

int main() {
    std::vector<int> nums_array = {37, 77, 89, 100, 979};
    std::vector<int> palindrome_array = find(nums_array);

    std::cout << "Integer palindromes: ";
    for (int num : palindrome_array) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}



