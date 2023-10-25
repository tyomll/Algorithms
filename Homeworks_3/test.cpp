#include <iostream>
#include <vector>

void InsertionSort(std::vector<int> & arr) {
    for (int i = 1; i < arr.size(); i++) {
        while (arr[i - 1] > arr[i]) {
            std::swap(arr[i - 1], arr[i]);
            i -= 1;
        }
    }
}
void print(std::vector<int> & arr) {
        std::cout << "{ ";
        for (auto element : arr) {
            std::cout << element << ", ";
        }
        std::cout << "\b\b }\n";
    }
int main() {
    std::vector<int> numbers{5, 4, 8, 2, 1, 3, 7, 9, 10, 6};
    InsertionSort(numbers);
    print(numbers);
    return 0;
}