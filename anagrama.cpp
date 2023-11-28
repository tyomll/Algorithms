#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::vector<std::string>> anagram_groups(const std::vector<std::string>& words) {
    std::unordered_map<std::string, std::vector<std::string>> anagram_map;

    for (const auto& word : words) {
        std::string word_signature(26, '0');
        for (char ch : word) {
            word_signature[ch - 'a']++;
        }
        anagram_map[word_signature].push_back(word);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& entry : anagram_map) {
        if (entry.second.size() > 1) {
            result.push_back(entry.second);
        }
    }

    return result;
}

int main() {
    std::vector<std::string> template_words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = anagram_groups(template_words);

    for (const auto& group : result) {
        std::cout << "[";
        for (const auto& word : group) {
            std::cout << "\"" << word << "\", ";
        }
        std::cout << "\b\b]\n";
    }

    return 0;
}

