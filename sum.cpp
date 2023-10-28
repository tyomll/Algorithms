#include<iostream>
#include <list>

std::list<int> addTwoNumbers(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> sum;
    int carry = 0;
    auto it1 = num1.begin();
    auto it2 = num2.begin();

    while (it1 != num1.end() || it2 != num2.end() || carry) {
        int value = carry;
        if (it1 != num1.end()) {
            value += *it1;
            ++it1;
        }
        if (it2 != num2.end()) {
            value += *it2;
            ++it2;
        }

        carry = value / 10;
        sum.push_back(value % 10);
    }

    return sum;
}

int main() {
    std::list<int> num1 = {2, 6, 8};
    std::list<int> num2 = {4, 5, 6};

    std::list<int> result = addTwoNumbers(num1, num2);

    for (int value : result) {
        std::cout << value ;
    }
    std::cout << "\n";

    return 0;
}
