#include <iostream>
#include <list>

std::list<int> rotate(std::list<int> top, int k) {
    for (int i = 0; i < k; ++i) {
        int tmp = top.back();
        top.pop_back();
        top.push_front(tmp);
    }
    return top;
}

void print(const std::list<int>& list) {
    std::cout << "{ ";
    for (auto i = list.begin(); i != list.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "}" << "\n";
}

int main() {
    std::list<int> list = {1, 2, 3, 4, 5};

    std::cout << "Original list" << "\n";
    print(list);
    int rotations = 3;
    list = rotate(list, rotations);
    std::cout << "List after rotations" << "\n";
    print(list);

    return 0;
}
