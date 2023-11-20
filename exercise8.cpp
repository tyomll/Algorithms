#include <iostream>
#include <vector>

void bubble_sorting(std::string& string) {
    for (int i = 0; i < string.size(); ++i) {
        for (int j = i + 1; j < string.size(); ++j) {
            if (string[i] > string[j]) {
                std::swap(string[i], string[j]);
            }
        }
    }
}

std::vector<std::vector<std::string>> anagrams_group(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> result;

    auto anagrama = [](const std::string& word1, const std::string& word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        std::string sorted_word1 = word1, sorted_word2 = word2;
        bubble_sorting(sorted_word1);
        bubble_sorting(sorted_word2);
        return sorted_word1 == sorted_word2;
    };

    for (int i = 0; i < strs.size(); ++i) {
        bool added = false;
        for (int j = 0; j < result.size(); ++j) {
            if (!result[j].empty() && anagrama(strs[i], result[j][0])) {
                result[j].push_back(strs[i]);
                added = true;
                break;
            }
        }
        if (!added) {
            result.push_back({strs[i]});
        }
    }

    return result;
}

int main() {
    std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};

    std::vector<std::vector<std::string>> group = anagrams_group(words);

    std::cout << "Anagram groups: " << "\n";
    for (int i = 0; i < group.size(); ++i) {
        for (int j = 0; j < group[i].size(); ++j) {
            std::cout << group[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
