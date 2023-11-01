#include <iostream>
#include <list>

std::list<int> findSum(std::list<int> list1, std::list<int> list2) {
    std::list<int> result;
    auto it1 = list1.end();
    auto it2 = list2.end();
    int biggestLength =
        list1.size() > list2.size() ? list1.size() : list2.size();

    int remainder = 0;

    for (size_t i = 0; i < biggestLength; i++) {
        int sum = 0;

        if (it1 != list1.begin() && it2 != list2.begin()) {
            --it1;
            --it2;
            sum += *it1 + *it2 + remainder;
        } else if (it1 != list1.begin() && it2 == list2.begin()) {
            --it1;
            sum += *it1 + remainder;
        } else if (it1 == list1.begin() && it2 != list2.begin()) {
            --it2;
            sum += *it2 + remainder;
        }

        if (sum >= 10) {
            remainder = 1;
        } else {
            remainder = 0;
        }

        result.push_front(sum % 10);
    }
    return result;
}

std::pair<std::list<int>, std::list<int>> inputLists() {
    std::list<int> list1;
    std::list<int> list2;
    std::string firstNumber, secondNumber;
    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;

    for (size_t i = 0; i < firstNumber.length(); i++) {
        list1.push_back(std::stoi(std::string(1, firstNumber[i])));
    }
    for (size_t i = 0; i < secondNumber.length(); i++) {
        list2.push_back(std::stoi(std::string(1, secondNumber[i])));
    }

    return std::make_pair(list1, list2);
}

void printList(const std::list<int> list) {
    for (const int &el : list) {
        std::cout << el;
    }
    std::cout << std::endl;
}

int main() {
    std::pair<std::list<int>, std::list<int>> lists = inputLists();
    std::list<int> result = findSum(lists.first, lists.second);
    printList(result);

    return 0;
}