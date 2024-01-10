#include <iostream>
#include <list>

using ListType = std::list<int>;

void printList(const ListType& list) {
    auto it = list.begin();

    while (it != list.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

ListType rotateList(ListType& list, const int& k) {
    for (size_t i = 0; i < k; i++) {
        auto lastElement = list.back();
        list.push_front(lastElement);
        list.pop_back();
    }

    return list;
}

int main() {
    ListType list = {0, 1, 2};
    int k = 4;

    printList(rotateList(list, k));

    return 0;
}