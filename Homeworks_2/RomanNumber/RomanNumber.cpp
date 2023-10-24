#include <iostream>
#include <unordered_map>

std::string intToRoman(int num) {
    std::unordered_map<int, std::string> romanMap = {
        {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"},
        {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"},
        {500, "D"}, {900, "CM"}, {1000, "M"}
    };

    std::string result = "";
    for (auto it = romanMap.begin(); it != romanMap.end(); ++it) {
        while (num >= it->first) {
            result += it->second;
            num -= it->first;
        }
    }

    return result;
}

int main() {
    int num;
    std::cout << "Enter integer: ";
    std::cin >> num;
    if (num <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }
    std::string romanNumeral = intToRoman(num);
    std::cout << "Roman numeral representation: " << romanNumeral << std::endl;

    return 0;
}
