#include <iostream>
#include <set>

std::pair<int, int> findIndexesOfTwo(std::multiset<int> multiset, int target) {
    auto start = multiset.begin();
    auto end = multiset.end();

    int firstIndex = 0, secondIndex = multiset.size();
    while (firstIndex < secondIndex) {
        if (*start + *end == target) {
            return std::make_pair(firstIndex, secondIndex);
        } else if (*start + *end < target) {
            start++;
            firstIndex++;

        } else {
            end--;
            secondIndex--;
        }
    }
    return std::make_pair(-1, -1);
}

std::multiset<int> inputMultiset() {
    std::multiset<int> multiset;
    int mapSize;

    std::cout << "Enter the size of map: ";
    std::cin >> mapSize;

    for (int i = 0; i < mapSize; i++) {
        int value;
        std::cout << "Enter value of element [" << i << "]: ";
        std::cin >> value;
        multiset.insert(value);
    }

    return multiset;
}

int main() {
    int target;
    std::multiset<int> multiset = inputMultiset();

    std::cout << "Input the target number: ";
    std::cin >> target;

    std::pair<int, int> indexes = findIndexesOfTwo(multiset, target);

    std::cout << indexes.first << " " << indexes.second << std::endl;
    return 0;
}