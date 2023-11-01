#include <iostream>
#include <list>
#include <sstream>

std::list<int> mergeLists(std::list<int> firstList, std::list<int> secondList) {
    std::list<int> mergedList;
    auto firstIterator = firstList.begin();
    auto secondIterator = secondList.begin();

    while (firstIterator != firstList.end() || secondIterator != secondList.end()) {
        if (firstIterator != firstList.end()) {
            mergedList.push_back(*firstIterator);
            firstIterator++;
        }
        if (secondIterator != secondList.end()) {
            mergedList.push_back(*secondIterator);
            secondIterator++;
        }
    }

    return mergedList;
}

std::pair<std::list<int>, std::list<int>> inputLists() {
    std::list<int> firstList;
    std::list<int> secondList;

    std::string firstListInput;
    std::cout << "Enter a list 1 of space-separated values: ";

    std::getline(std::cin, firstListInput);
    std::istringstream iss(firstListInput);
    int num;

    while (iss >> num) {
        firstList.push_back(num);
    }

    std::string secondListInput;
    std::cout << "Enter a list 2 of space-separated values: ";

    std::getline(std::cin, secondListInput);
    std::istringstream isss(secondListInput);
    int num1;

    while (isss >> num1) {
        secondList.push_back(num1);
    }

    return std::make_pair(firstList, secondList);
}

int main() {
    std::pair<std::list<int>, std::list<int>> lists = inputLists();
    std::list<int> mergedList = mergeLists(lists.first, lists.second);

    for (const int& el : mergedList) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}