#include <iostream>
#include <stack>
#include <map>

bool valid_braces(std::string braces) {
    std::stack<char> temp;
    std::map<char, char> matching_pairs = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char pair : braces) {
        if (matching_pairs.find(pair) != matching_pairs.end()) {
            if (temp.empty() || temp.top() != matching_pairs[pair]) {
                return false;
            }
            temp.pop(); 
        } else {
            temp.push(pair);
        }
    }
    return temp.empty();
}

int main() {
    std::string braces = "{[(])}";
    if (valid_braces(braces)) {
        std::cout << "Correct" << "\n";
    } else {
        std::cout << "Incorrect" << "\n";
    }
    return 0;
}
