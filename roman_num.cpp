#include <iostream>
#include <vector>


std::string to_roman(int arabic_num) {

    const std::vector<std::string> roman_symbols = {
    "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    const std::vector<int> roman_values = {
    1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    std::string roman_num;

    for (size_t i = 0; i < roman_symbols.size(); ++i) {
        while (arabic_num >= roman_values[i]) {
            roman_num += roman_symbols[i];
            arabic_num -= roman_values[i];
        }
    }

    return roman_num;
}

int main() {
    int arabic_num;

    std::cout << "Enter an arabic number: ";
    std::cin >> arabic_num;

    std::string roman_num = to_roman(arabic_num);

    std::cout << "Roman number: " << roman_num << std::endl;

    return 0;
}
