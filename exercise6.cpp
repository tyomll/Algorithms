#include<iostream>
#include<list>

std::list<int> List(std::list<int> first, std::list<int> second) {
    std::list<int> result;
    auto i1 = first.begin();
    auto i2 = second.begin();
    
    while (i1 != first.end() && i2 != second.end()) {
        if (*i1 < *i2) {
            result.push_back(*i1);
            ++i1;
        } else {
            result.push_back(*i2);
            ++i2;
        }
    }

    while (i1 != first.end()) {
        result.push_back(*i1);
        ++i1;
    }

    while (i2 != second.end()) {
        result.push_back(*i2);
        ++i2;
    }

    return result;
}

void print(std::list<int>& list) {
    for (auto i : list) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << "The first element: " << list.front() << "\n";
}

int main() {
    std::list<int> first = {2, 6, 8};
    std::list<int> second = {4, 5, 6};
    std::list<int> result = List(first, second);
    print(result);

    return 0;
}
