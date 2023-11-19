#include <iostream>
#include <list>

std::list<int> merged_list(std::list<int>& list_1, std::list<int>& list_2) {
    auto first = list_1.begin();
    auto second = list_2.begin();
    std::list<int> result;

    while (first != list_1.end() && second != list_2.end()) {
        if (*first < *second) {
            result.push_back(*first);
            ++first;
        } else {
            result.push_back(*second);
            ++second;
        }
    }

    while (first != list_1.end()) {
        result.push_back(*first);
        ++first;
    }

    while (second != list_2.end()) {
        result.push_back(*second);
        ++second;
    }

    return result;
}

int main() {
    std::list<int> firstList = {-1, 2, 4};
    std::list<int> secondList = {1, 3, 4};
    std::list<int> result = merged_list(firstList, secondList);
    
    if (!result.empty()) {
        std::cout << "First element of the merged list: " << result.front() << std::endl;
    } else {
        std::cout << "The merged list is empty." << std::endl;
    }

    return 0;
}
