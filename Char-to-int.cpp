#include <iostream>
#include <vector>

std::vector<int> char_int(const std::vector<char>& arr) {
    std::vector<int> result;
    
    for (char charecter : arr) {
        if (charecter >= '0' && charecter <= '9') {
            int int_value = charecter - '0';
            result.push_back(int_value);
        }
    }
    
    return result;
}

int main() {
    std::vector<char> arr = {'3', '8', '4', '5', '6'};
    std::vector<int> result = char_int(arr);
    for (int item : result) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}