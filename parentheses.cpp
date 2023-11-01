#include <iostream>
#include <stack>
#include <string>

bool isValid(std::string s) {
    std::stack<char> parentheses;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            parentheses.push(c);
        }
		else {
            if (parentheses.empty()) {
                return false;
            }

            char top = parentheses.top();
            parentheses.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false; 
            }
        }
    }

    return parentheses.empty(); 
}

int main() {
    std::string s;
    std::cout << "Enter a line of parentheses: ";
    std::cin >> s;

	if(isValid(s)){
		std::cout <<  "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
    return 0;
}

