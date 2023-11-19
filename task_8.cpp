#include <iostream>
#include <vector>

void string_sorting(std::string& str) {
    for (int i = 0; i < str.size(); ++i) {
        for (int j = i + 1; j < str.size(); ++j) {
            if (str[i] > str[j]) {
                std::swap(str[i], str[j]);
            }
        }
    }
}

bool anagram(const std::string& str1, const std::string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }

    std::string sorted_str1 = str1, sorted_str2 = str2;
    string_sorting(sorted_str1);
    string_sorting(sorted_str2);

    return sorted_str1 == sorted_str2;
}

std::vector<std::vector<std::string>> anagrams_group(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> result;

    for (int i = 0; i < strs.size(); ++i) {
        bool added = false;
        for (int j = 0; j < result.size(); ++j) {
            if (!result[j].empty() && anagram(strs[i], result[j][0])) {
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

    std::cout << "Anagram groups: " << std::endl;
    for (int i = 0; i < group.size(); ++i) {
        for (int j = 0; j < group[i].size(); ++j) {
            std::cout << group[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
