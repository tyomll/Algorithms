#include <iostream>
#include <vector>

std::vector<int>  ChatToInt(std::vector<char>& arr) {
    std::vector<int> result;
    
    for (char charecter : arr) {
        if (charecter >= '0' && charecter <= '9') {
            int intValue = charecter - '0';
            result.push_back(intValue);
        }
    }
    
    return result;
}

int main() {
    std::vector<char> arr = {'1', '2', '3', '4', '5'};
    std::vector<int> result =  ChatToInt(arr);
    for (int item : result) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}