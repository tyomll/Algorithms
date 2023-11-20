#include <iostream>
#include <list>

template <typename T>
void bubbleSort(std::list<T>& myList) {
    bool swapped;
    do {
        swapped = false;
        for (auto it = myList.begin(); it != std::prev(myList.end()); ++it) {
            auto nextIt = std::next(it);
            if (*it > *nextIt) {
                std::swap(*it, *nextIt);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    std::list<int> myList = {5, 2, 8, 1, 3};
    bubbleSort(myList);
    std::cout << "Sorted list: ";
    for (const auto& element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
