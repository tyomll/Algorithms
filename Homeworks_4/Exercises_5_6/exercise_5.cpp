#include <iostream>
#include <sstream>
#include <string>
#include <list>

std::list<int> merge(std::list<int>& list1, std::list<int>& list2) {
    auto i = list1.begin();
    auto j = list2.begin();
    std::list<int> result;
    while (i != list1.end() && j != list2.end()) {
        if (*i > *j) {
            result.push_back(*j);
            ++j;
        }
        else {
            result.push_back(*i);
            ++i;
        }
    }
    while (i != list1.end()) {
        result.push_back(*i);
        ++i;
    }
    while (j != list2.end()) {
        result.push_back(*j);
        ++j;
    }
    return result;
}

std::list<int> insert() {
    std::list<int> list;
    std::cout << "Enter numbers separated by spaces (e.g., 1 2 3 4): ";
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    int number;
    while (iss >> number) {
        list.push_back(number);
    }

    return list;
}

void print(std::list<int>& list) {
    std::cout << "List { ";
    for (auto element : list) {
        std::cout << element << " ";
    }
    std::cout << "\b }\n";
}

int main() {
    std::list<int> list1, list2, mergelist;
    std::cout << "List 1: ";
    list1 = insert();
    std::cout << "List 2: ";
    list2 = insert();
    mergelist = merge(list1, list2);
    print(mergelist);
    return 0;
}