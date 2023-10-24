#include <iostream>
#include <vector>

bool isPalindrome(int num) {
    int reversedNum = 0;
    int originalNum = num;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    return originalNum == reversedNum;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::vector<int> arr(size);

    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Palindromic numbers are: ";
    for (const auto& num : arr) {
        if (isPalindrome(num)) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

