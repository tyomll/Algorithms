#include <iostream>
#include <list>

std::list<int> rotateList(std::list<int>& list, int k) {
    while (k > 0) {
        int tmp = list.back();
        list.pop_back();
        list.push_front(tmp);
        k--;
    }

    return list;
}

void print(std::list<int>& list) {
    for (int element : list) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> list = {1, 5, 2, 8};
    std::list<int> result = rotateList(list, 3);
    print(result);
    return 0;
}