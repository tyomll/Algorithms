#include <iostream>
#include <stack>

bool check(const std::string &row) {
    std::stack<char> temp;

    for (char brace : row) {
        if (brace == '(' || brace == '[' || brace == '{') {
            temp.push(brace);
        }
        else if (brace == ')' || brace == ']' || brace == '}') {
            if (temp.empty()) {
                return false;
            }

            char top = temp.top();
            temp.pop();

            if ((brace == ')' && top != '(') || (brace == ']' && top != '[') || (brace == '}' && top != '{')) {
                return false;
            }
        }
    }

    return temp.empty();
}

int main() {
    std::string row = "[{}]";
    if (check(row)) {
        std::cout << "True\n";
    }
    else {
        std::cout << "False\n";
    }
    
    return 0;
}