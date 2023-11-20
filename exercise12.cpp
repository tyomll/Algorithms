#include <iostream>
#include <list>

void print(const std::list<int>& list) {
    for (const auto& i : list) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

std::list<int> merge(const std::list<int>& left, const std::list<int>& right) {
    std::list<int> result;

    auto left_element = left.begin();
    auto right_element = right.begin();

    while (left_element != left.end() && right_element != right.end()) {
        const auto& left1 = *left_element;
        const auto& right1 = *right_element;

        if (left1< right1) {
            result.push_back(left1);
            ++left_element;
        } else {
            result.push_back(right1);
            ++right_element;
        }
    }
    result.insert(result.end(), left_element, left.end());
    result.insert(result.end(), right_element, right.end());

    return result;
}

std::list<int> merge_sort(std::list<int> list) {
    if (list.size() <= 1) {
        return list;
    }
    std::list<int> left, right;
    auto mid = list.size() / 2;
    auto element = list.begin();
    for (int i = 0; i < mid; ++i) {
        left.push_back(*element);
        ++element;
    }
    while (element != list.end()) {
        right.push_back(*element);
        ++element;
    }
    left = merge_sort(left);
    right = merge_sort(right);
    return merge(left, right);
}

int main() {
    std::list<int> list = {4, 8, 6, 2};
    std::cout << "Original list: ";
    print(list);
    list = merge_sort(list);
    std::cout << "Sorted list: ";
    print(list);
    return 0;
}