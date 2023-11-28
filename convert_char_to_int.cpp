#include <iostream>
#include <vector>

std::vector<int> convert(std::vector<char>& characters) {
    std::vector<int> converted_values;
    
    for (char ch : characters) {
        if (ch >= '0' && ch <= '9') {
            int int_value = ch - '0';
            converted_values.push_back(int_value);
        }
    }
    
    return converted_values;
}

int main() {
    std::vector<char> char_array = {'1', '2', '3', '4', '5'};
    std::vector<int> result = convert(char_array);
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

