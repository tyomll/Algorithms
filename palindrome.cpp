#include <iostream>
#include <vector>

bool palindrome(int num) {
    int reversed = 0;
    int original = num;

    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int array[size];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    std::cout << "Palindromic numbers are: ";
    for (int i = 0; i < size; i++) {   
        if (palindrome(array[i])) {
            std::cout << array[i] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

