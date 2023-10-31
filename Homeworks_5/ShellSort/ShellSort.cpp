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
    std::cout << "}" << std::endl;
}

std::vector<int>& insertionsort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int curent = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > curent) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curent;
    }
    return arr;
}

void shellsort(std::vector<int>& arr) {
    int n = arr.size() / 2;
    while (n >= 1) {
        for (int i = 0; i < arr.size() - n; i++) {
            if (arr[i] > arr[i + n]) {
                std::swap(arr[i], arr[i + n]);
            }
        }
        n /= 2;
    }
    arr = insertionsort(arr);
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
    shellsort(arr);
    std::cout << "Sorted array:\t";
    print(arr);
    return 0;
}