#include <iostream>
#include <stack>
#include <map>

bool correct_parenthesis(std::string& parenthesis) {
    std::stack<char> tmp;
    std::map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

    for(int i = 0; i < parenthesis.length(); ++i) {
        char current = parenthesis[i];

        if (mapping.find(current) != mapping.end()) {
            if (!tmp.empty()) {
                char top = tmp.top();
                tmp.pop();
                if (top != mapping[current]) {
                    return false;
                }
            } else {
                return false; 
            }
        } else {
            tmp.push(current);
        }
    }

    return tmp.empty();
}

int main() {
    std::string parenthesis = "{[()]}";

    if (!correct_parenthesis(parenthesis)) {
        std::cout << "Uncorrect parenthesis!" << "\n";
        return 0;
    }
    
    std::cout << "Correct parenthesis!" << "\n";
    return 0;
}
