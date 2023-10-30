#include <iostream>
#include <string>
#include <vector>

std::string toRoman(int number) {

    std::vector<std::pair<int, std::string>> romanNumerals{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    std::string result;

    for (const auto &pair : romanNumerals) {
        while (number >= pair.first) {
            result += pair.second;
            number -= pair.first;
        }
    }

    return result;
}
int main() {
    int inputNumber;
    std::cout << "Enter a number (between 1 and 3999) ";
    std::cin >> inputNumber;
    std::cout << "The Roman number is " << toRoman(inputNumber) << std::endl;

    return 0;
}

