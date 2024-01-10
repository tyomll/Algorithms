#include <iostream>
#include <map>

bool validBraces(std::string s) {
    std::map<char, int> pairs;
    std::map<char, char> validPairs;

    validPairs['('] = ')';
    validPairs['['] = ']';
    validPairs['{'] = '}';

    for (size_t i = 0; i < s.length(); i++) {
        std::map<char, int>::iterator it = pairs.find(s[i]);
        if (it != pairs.end()) {
            it->second += 1;
        } else {
            std::pair<char, int> pair;
            pair.first = s[i];
            pair.second = 1;
            pairs.insert(pair);
        }
    }

    for (const std::pair<char, char>& el : validPairs) {
        if (pairs[el.first] != pairs[el.second]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string s = "(()[]{}";

    std::cout << (validBraces(s) ? "true" : "false") << std::endl;

    return 0;
}