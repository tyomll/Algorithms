#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void print(std::vector<int>& arr) {
    auto item = arr.begin();
    std::cout << "{ ";
    while (item != arr.end()) {
        std::cout << *item << " ";
        item++;
    }
    std::cout << "}\n" << std::endl;
}

void make_heap(std::vector<int>& arr) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        int n = arr.size() - 1;
        while (n >= 0) {
            if (arr[n] < arr[(n - 1) / 2]) {
                std::swap(arr[n], arr[(n - 1) / 2]);
                sorted = false;
            }
            n--;
        }
    }
}

void sort_heap(std::vector<int>& arr) {
    std::vector<int> tmp;
    int size = arr.size();
    int n = 0;
    while (n < size) {
        tmp.push_back(arr[0]);
        std::swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        make_heap(arr);
        n++;
    }
    arr = tmp;
}

int main() {
    std::vector<int> arr;
    std::cout << "Enter numbers separated by spaces (e.g., 1 2 3 4): ";
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    int number;
    while (iss >> number) {
        arr.push_back(number);
    }
    std::cout << std::endl;
    std::cout << "First array: \t";
    print(arr);
    make_heap(arr);
    std::cout << "Heap array: \t";
    print(arr);
    sort_heap(arr);
    std::cout << "Sorted array: \t";
    print(arr);
    return 0;
}