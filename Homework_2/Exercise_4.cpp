#include <iostream>
#include <list>

std::list<int> insertArr(std::list<int>& arr1, std::list<int>& arr2) {
    std::list<int> result;
    auto item1 = arr1.begin();
    auto item2 = arr2.begin();
    int x = 0;

    while (item1 != arr1.end() || item2 != arr2.end() || x != 0) {
        int sum = x;
        if (item1 != arr1.end()) {
            sum += *item1;
            ++item1;
        }
        if (item2 != arr2.end()) {
            sum += *item2;
            ++item2;
        }

        x = sum / 10;
        result.push_front(sum % 10);
    }

    return result;
}


void printArr(std::list<int>& arr) {
    auto first = arr.begin();
    while (first != arr.end()) {
        std::cout << *first;
        first++;
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> num1, num2, result;
    num1.push_back(6); 
    num1.push_back(5); 
    num1.push_back(1);
    num2.push_back(7); 
    num2.push_back(8); 
    num2.push_back(9);
    result = insertArr(num1, num2);
    std::cout << "Number 1: ";
    printArr(num1);
    std::cout << "Number 2: ";
    printArr(num2);
    std::cout << "Result: ";
    printArr(result);
    
    return 0;
}