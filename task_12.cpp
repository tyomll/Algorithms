#include <iostream>
#include <list>

std::list<int> merge(std::list<int>& left, std::list<int>& right){
    std::list<int> result;
    auto left1 = left.begin();
    auto right1 = right.begin();

    while (left1 != left.end() && right1 != right.end()) {
        const auto& left_element = *left1;
        const auto& right_element = *right1;

        if (left_element < right_element) {
            result.push_back(left_element);
            ++left1;
        } else {
            result.push_back(right_element);
            ++right1;
        }
    }

    result.insert(result.end(), left1, left.end());

    result.insert(result.end(), right1, right.end());

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

void print_list(const std::list<int>& list) {
    for (const auto& element : list) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

int main() {
    std::list<int> my_list = {3, 1, 4, 2};

    std::cout << "Original list: ";
    print_list(my_list);

    my_list = merge_sort(my_list);

    std::cout << "Sorted list: ";
    print_list(my_list);

    return 0;
}