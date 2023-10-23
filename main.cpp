#include <iostream>
#include <set>
#include <vector>

std::vector<std::string> getMatching(
    std::pair<std::set<std::string>, std::set<int>> pair) {
    std::vector<std::string> result;
    std::set<std::string> letters = pair.first;
    std::set<int> numbers = pair.second;

    auto iteratorLetters = letters.begin();
    auto iteratorNumbers = numbers.begin();

    while (iteratorLetters != letters.end()) {
        result.push_back(*iteratorLetters + std::to_string(*iteratorNumbers));
        iteratorLetters++;
        iteratorNumbers++;
    }

    return result;
}

std::pair<std::set<std::string>, std::set<int>> inputSets() {
    size_t setLength;
    std::set<std::string> letters;
    std::set<int> numbers;

    std::cout << "Enter the length of sets: ";
    std::cin >> setLength;

    int i = 0;
    while (i < setLength) {
        std::string lettersInput;
        int numbersInput;
        std::cout << "Input letters[" << i << "] : ";
        std::cin >> lettersInput;
        letters.insert(lettersInput);

        std::cout << "Input numbers[" << i << "] : ";
        std::cin >> numbersInput;
        numbers.insert(numbersInput);

        i++;
    }

    return std::make_pair(letters, numbers);
}

int main() {
    std::pair<std::set<std::string>, std::set<int>> pair = inputSets();
    std::vector<std::string> result = getMatching(pair);

    for (std::string el : result) {
        std::cout << el << ", ";
    }
    return 0;
}