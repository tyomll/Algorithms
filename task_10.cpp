#include <iostream>
#include <list>

std::list<int> rotate(std::list<int> head, int k) {
    for (int i = 0; i < k; ++i) {
        int tmp = head.back();
        head.pop_back();
        head.push_front(tmp);
    }
    return head;
}

void print_list(const std::list<int>& my_list) {
    std::cout << "{ ";
    for (auto i = my_list.begin(); i != my_list.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "}" << "\n";
}

int main() {
    std::list<int> my_list = {1, 2, 3, 4, 5};

    std::cout << "Original list: ";
    print_list(my_list);

    int rotations = 2;
    my_list = rotate(my_list, rotations);

    std::cout << "List after " << rotations << " rotations: ";
    print_list(my_list);

    return 0;
}
