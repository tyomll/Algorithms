#include <iostream>
#include <vector>

void sort_list(std::vector<int>& connectedList) {
    for (size_t i = 0; i < connectedList.size(); ++i) {
        for (size_t j = i + 1; j < connectedList.size(); ++j) {
            if (connectedList[i] > connectedList[j]) {
                int temp = connectedList[i];
                connectedList[i] = connectedList[j];
                connectedList[j] = temp;
            }
        }
    }
}

int main() {
    std::vector<int> connectedList = {5, 2, 9, 1, 6};

    
    sort_list(connectedList);

    std::cout << "Sorted list in ascending order: ";
    for (const auto& elem : connectedList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
