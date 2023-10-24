#include <iostream>
#include <unordered_map>

std::string intToRoman(int number) {
    std::unordered_map<int, std::string> keyValue = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

    std::string result = "";
    for (auto item = keyValue.begin(); item != keyValue.end(); ++item) {
        while (number >= item->first) {
            result += item->second;
            number -= item->first;
        }
    }

    return result;
}

int main() {
    int num;
    std::cout << "Enter the number: ";
    std::cin >> num;
    std::string romanNumber = intToRoman(num);
    std::cout << "Roman numeber: " << romanNumber << std::endl;

    return 0;
}