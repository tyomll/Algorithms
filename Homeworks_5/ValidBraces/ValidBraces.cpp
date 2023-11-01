#include <iostream>
#include <stack>
#include <string>

bool valid_or_not(const std::string &braces) {
    std::stack<char> tmp_braces;

    for (char brace : braces) {
        if (brace == '(' || brace == '[' || brace == '{') {
            tmp_braces.push(brace);
        }
        else if (brace == ')' || brace == ']' || brace == '}') {
            if (tmp_braces.empty()) {
                return false;
            }

            char top = tmp_braces.top();
            tmp_braces.pop();

            if ((brace == ')' && top != '(') ||
                (brace == ']' && top != '[') ||
                (brace == '}' && top != '{')) {
                return false;
            }
        }
    }

    return tmp_braces.empty();
}

int main() {
    std::string braces = "[({[}])]";
    std::cout << (valid_or_not(braces) ? "true" : "false") << std::endl;
    return 0;
}
