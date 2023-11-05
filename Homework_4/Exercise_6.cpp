#include <iostream>
#include <list>

std::list<int> listSort(std::list<int>& firstList, std::list<int>& secondList) {
    auto first = firstList.begin();
    auto second = secondList.begin();
    std::list<int> result;

    while (first != firstList.end() && second != secondList.end()) {
        if (*first < *second) {
            result.push_back(*first);
            ++first;
        }
        else {
            result.push_back(*second);
            ++second;
        }
    }

    while (first != firstList.end()) {
        result.push_back(*first);
        ++first;
    }

    while (second != secondList.end()) {
        result.push_back(*second);
        ++second;
    }
    
    return result;
}

void printList(std::list<int>& list) {
    for (auto item : list) {
        std::cout << item << std::endl;
    }
    
}

int main() {
    std::list<int> firstList = {1, 2, 4};
    std::list<int> secondList = {1, 3, 4};
    std::list<int> result = listSort(firstList, secondList);
    printList(result);

    return 0;
}