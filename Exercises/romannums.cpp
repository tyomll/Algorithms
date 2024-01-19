#include <iostream>
#include <string>

std::string intToRoman(int number) {
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const std::string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    std::string result = "";
    for (int i = 0; i < 13; i++) {
        while (number >= values[i]) {
            result += numerals[i];
            number -= values[i];
        }
    }

    return result;
}

int main() {
    int num;
    std::cout << "Enter the number: ";
    std::cin >> num;
    std::string romanNumber = intToRoman(num);
    std::cout << "Roman number: " << romanNumber << std::endl;

    return 0;
}
