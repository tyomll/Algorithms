#include <iostream>
#include <unordered_map>

int romanToInt(std::string roman) {
    int sum = 0;
    std::unordered_map<char, int> definitions = {
        {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};
    for (size_t i = 0; i < roman.length(); i++) {
        sum += definitions[roman[i]];
    }
    return sum;
}

int main() {
    std::string romanNumber;
    std::cout << "Enter roman number: ";
    std::cin >> romanNumber;
    std::cout << romanToInt(romanNumber) << std::endl;

    return 0;
}