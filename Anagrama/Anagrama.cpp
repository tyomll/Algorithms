#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::string sortString(const std::string& s) {
    std::string sorted = s;
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}

std::vector<std::vector<std::string>> anagramGroups(const std::vector<std::string>& words) {
    std::unordered_map<std::string, std::vector<std::string>> anagramMap;

    for (const auto& word : words) {
        std::string sortedWord = sortString(word);
        anagramMap[sortedWord].push_back(word);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& entry : anagramMap) {
        if (entry.second.size() > 1) {
            result.push_back(entry.second);
        }
    }

    return result;
}

int main() {
    std::vector<std::string> templateWords = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = anagramGroups(templateWords);

    for (const auto& group : result) {
        std::cout << "[";
        for (const auto& word : group) {
            std::cout << "\"" << word << "\", ";
        }
        std::cout << "\b\b]\n";
    }

    return 0;
}
