#include <iostream>
#include <list>

std::list<int> add_two_numbers(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> sum;
    int carry = 0;
    auto num1_iter = num1.rbegin();  
    auto num2_iter = num2.rbegin();  
    while (num1_iter != num1.rend() || num2_iter != num2.rend() || carry) {
        int value = carry;

        if (num1_iter != num1.rend()) {
            value += *num1_iter;
            ++num1_iter;
        }

        if (num2_iter != num2.rend()) {
            value += *num2_iter;
            ++num2_iter;
        }

        carry = value / 10;
        sum.push_front(value % 10);
    }

    return sum;
}

int main() {
    std::list<int> num1 = {7, 4, 5};
    std::list<int> num2 = {4, 9, 6};

    std::list<int> result = add_two_numbers(num1, num2);

    for (int value : result) {
        std::cout << value;
    }
    std::cout << "\n";

    return 0;
}
