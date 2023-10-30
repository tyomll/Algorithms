#include <iostream>
#include <string>
#include <map>

std::string intToRoman(int num) {
    std::string res = "";
    
    std::map<int, std::string, std::greater<int>> roman; 
	roman[1000] = "M";
    roman[900] = "CM";
    roman[500] = "D";
    roman[400] = "CD";
    roman[100] = "C";
    roman[90] = "XC";
    roman[50] = "L";
    roman[40] = "XL";
    roman[10] = "X";
    roman[9] = "IX";
    roman[5] = "V";
    roman[4] = "IV";
    roman[1] = "I";
    
    for (const auto& elem : roman) {
        while (num >= elem.first) {
            res += elem.second;
            num -= elem.first;
        }
    }
    
    return res;
}

int main() {
	int num;
	std::cout << "Input the number: ";
	std::cin >> num;
    
    std::cout << num << " : " << intToRoman(num) << std::endl;
    
    return 0;
}

