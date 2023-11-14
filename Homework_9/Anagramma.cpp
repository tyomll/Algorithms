#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> anagramma(const std::vector<std::string>& arr) {
    std::unordered_map<std::string, std::vector<std::string>> anagramGroup;

    for (const auto& word : arr) {
        std::string sortedWord = word;
        std::sort(sortedWord.begin(), sortedWord.end());
        anagramGroup[sortedWord].push_back(word);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& entry : anagramGroup) {
        result.push_back(entry.second);
    }

    return result;
}

void printVector(std::vector<std::vector<std::string>>& arr) {
    for (const auto& word : arr) {
        for (std::string element : word) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = anagramma(words);
    printVector(result);

    return 0;
}
