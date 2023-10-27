#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
std::vector<int>& insert(std::vector<int>& numbers) {
    std::string input;
    std::cout << "Enter numbers separated by spaces (e.g., 1 2 3 4): ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    int number;
    while (iss >> number) {
        numbers.push_back(number);
    }
    return numbers;
}
void print(std::vector<int>& arr) {
    std::cout << "Sorted array { ";
    for (auto element : arr) {
        std::cout << element << ", ";
    }
    std::cout << "\b\b }\n";
}

int main() {
    std::vector<int> numbers;
    print(insertionsort(insert(numbers)));
    return 0;
}