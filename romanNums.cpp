#include <iostream>

std::string Roman(int num) {
    
    int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    std::string result = "";
    for (int i = 0; i < 13; i++) {
        while (num >= numbers[i]) {
            num -= numbers[i];
            result += symbols[i];
        }
    }

    return result;
}

int main() {
    int num;
    std::cout << "Enter the integer number " ;
    std::cin >> num;

    std::string roman = Roman(num);
    std::cout << "The roman number " <<  roman << std::endl;

    return 0;
}
