#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int>& selectionsort(std::vector<int>& arr){
    int index = 0, size = arr.size();
    while (index < size) {
        int minindex = index; 
        for (int i = index; i < size; i++) {
            if (arr[index] > arr[i] && arr[i] < arr[minindex]) {
                minindex = i;
            }
        }
        std::swap(arr[index], arr[minindex]);
        index++;
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
    print(selectionsort(insert(numbers)));
    return 0;
}