#include <iostream>
#include <list>

std::list<int> sortList(std::list<int>& list) {
    auto element = list.begin();
    int listSize = list.size();
    std::list<int> result;
    for (int i = 0; i < listSize; ++i) {
        for (auto it = ++list.begin(); it != list.end() ; it++) {
            if (*it > *element) {
                element = it;
            }
        }
        list.erase(element);
        result.push_front(*element);
        element = list.begin();
    }

    return result;
}

void printList(std::list<int>& list) {
    for (int element : list) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> list = {4, 2, 1, 3};
    std::list<int> result = sortList(list);
    printList(result);

    return 0;
}