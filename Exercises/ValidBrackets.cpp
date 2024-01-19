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
                        std::cout << tmp_braces.top();

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
    std::string braces = "({[{}]})";
  
    if (valid_or_not(braces)) {
        std::cout << "The input string is valid." << std::endl;
    } else {
        std::cout << "The input string is invalid." << std::endl;
    }  return 0;
}