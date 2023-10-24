#include <iostream>
#include <string>
#include <unordered_map>

std::string intToRoman(int num)
{
    if (num <= 0 || num >= 4000)
    {
        return "Invalid number";
    }

    std::unordered_map<int, std::string> romanMap = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};

    std::string result = "";

    for (const auto &entry : romanMap)
    {
        while (num >= entry.first)
        {
            result += entry.second;
            num -= entry.first;
        }
    }

    return result;
}

int main()
{
    int number = 2498;
    std::string romanNumeral = intToRoman(number);
    std::cout << "Roman numeral for " << number << " is " << romanNumeral << std::endl;

    return 0;
}
