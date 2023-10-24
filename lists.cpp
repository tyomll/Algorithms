#include <iostream>
#include <list>

std::list<int> adding(const std::list<int>& arr1, const std::list<int>& arr2) {
    int carry_sum = 0;
   
    std::list<int> result;
    std::list<int> list1 = arr1;
    std::list<int> list2 = arr2;

    while (!list1.empty() || !list2.empty() || carry_sum != 0) {
        int digit1 = 0, digit2 = 0;
        
        if (!list1.empty()) {
            digit1 = list1.back();
            list1.pop_back();
        }
        if (!list2.empty()) {
            digit2 = list2.back();
            list2.pop_back();
        }

        int sum = carry_sum + digit1 + digit2;
        
        carry_sum = sum / 10;
        result.push_front(sum % 10);
    }

    return result;
}

int main() {
    std::list<int> num1 = {1, 5, 6};
    std::list<int> num2 = {9, 8, 7};

    std::list<int> add = adding(num1, num2);

    std::cout << "First Number: ";
    for (auto it = num1.begin(); it != num1.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;

    std::cout << "Second Number: ";
    for (auto it = num2.begin(); it != num2.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;

    std::cout << "Sum: ";
    for (auto it = add.begin(); it != add.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}
