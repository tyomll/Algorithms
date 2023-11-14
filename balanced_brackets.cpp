#include <iostream>

bool isBalanced(const std::string& expr) {
    int balance = 0;
    for (std::size_t i = 0; i < expr.length(); ++i) {
        char ch = expr[i];
        balance += (ch == '(') - (ch == ')');
        balance += (ch == '{') - (ch == '}');
        balance += (ch == '[') - (ch == ']');

        if (balance < 0) {
            return false;
        }
    }

    return balance == 0;
}

int main() {
    std::string expression;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    if (isBalanced(expression)) {
        std::cout << "The parentheses are balanced." << std::endl;
    } else {
        std::cout << "The parentheses are not balanced." << std::endl;
    }

    return 0;
}

