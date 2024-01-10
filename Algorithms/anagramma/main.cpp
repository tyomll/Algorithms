#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using anagrammReturnType = std::map<std::string, std::vector<std::string>>;

anagrammReturnType getAnagramm(const std::vector<std::string>& words) {
    std::map<std::string, std::vector<std::string>> result;

    for (const std::string& word : words) {
        std::string sortedWord = word;
        std::sort(sortedWord.begin(), sortedWord.end());
        result[sortedWord].push_back(word);
    }

    return result;
}

void printAnagramms(
    const std::map<std::string, std::vector<std::string>>& words) {
    auto itStart = words.begin();
    auto itEnd = words.end();
    while (itStart != itEnd) {
        std::cout << "[ ";
        for (size_t i = 0; i < itStart->second.size(); i++) {
            std::cout << itStart->second[i]
                      << (itStart->second.size() - 1 == i ? "" : ", ");
        }
        std::cout << " ]" << std::endl;

        itStart++;
    }
}
int main() {
    std::vector<std::string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};

    printAnagramms(getAnagramm(arr));
    return 0;
}