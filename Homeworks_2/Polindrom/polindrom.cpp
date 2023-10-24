#include <iostream>
#include <vector>

std::vector<int> polindrom(std::vector<int> arr) {
    std::vector<int> tmp;
    for (int i = 0; i < arr.size(); i++) {
        bool pol = true;
        std::string element = std::to_string(arr[i]);
        for (int j = 0; j < element.size() / 2; j++) {
            if (element[j] != element[element.size() - 1 - j]) {
                pol = false;
            }
        }
        if (pol) {
            tmp.push_back(arr[i]);
        }
    }
    return tmp;
}
void print(std::vector<int>& arr) {
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> myArray = {37, 77, 89, 100, 979};
    std::vector<int> polidrom_array = polindrom(myArray);
    print(polidrom_array);
    return 0;
}