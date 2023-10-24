#include <iostream>
#include <vector>

void insertArr(std::vector<int>& vec, int count) {
    int item;
    for (int i = 0; i < count; ++i) {
        std::cout << "Array[" << i << "] = ";
        std::cin >> item;
        vec.push_back(item);
    }
}

void printArr(std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << "Array[" << i << "] = " << vec[i] << std::endl;
    }
}

std::vector<int> checkPolindrome(std::vector<int>& vec) {
    std::vector<int> result;
    bool check = true;
    std::string number;
    for (int i = 0; i < vec.size(); ++i) {
        number = std::to_string(vec[i]);
        for (int j = 0; j < number.size() / 2; ++j) {
            if (number[j] != number[number.size() - 1 - j]) {
                check = false;
                break;
            }
        }
        if (check) {
            result.push_back(vec[i]);
        }
        check = true;
    }

    return result;
}

int main() {
    int count;
    std::vector<int> firstVector, result;
    std::cout << "Enter elements count: ";
    std::cin >> count;
    insertArr(firstVector, count);
    result = checkPolindrome(firstVector);
    std::cout << "\nAnswer array\n\n";
    printArr(result);

    return 0;
}