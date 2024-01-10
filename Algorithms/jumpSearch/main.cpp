#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

int jumpSearch(const std::vector<int>& arr, const int& target) {
    int jumpRange = std::sqrt(arr.size() - 1);

    int i = 0;
    while (i < arr.size()) {
        if (arr[i] == target) {
            return i;
        }
        if (arr[i] < target) {
            if (i + jumpRange >= arr.size()) {
                for (size_t j = i + 1; j < arr.size(); j++) {
                    if (arr[j] == target) {
                        return j;
                    }
                }
            }
            i += jumpRange;
        }
        if (arr[i] > target) {
            for (size_t j = i / 2 - 1; j < i; j++) {
                if (arr[j] == target) {
                    return j;
                }
            }
            return -1;
        }
    }
    return -1;
}

std::vector<int> inputArr() {
    std::vector<int> arr;

    std::string arrInput;
    std::cout << "Enter a array of space-separated values: ";

    std::getline(std::cin, arrInput);
    std::istringstream iss(arrInput);
    int num;

    while (std::getline(iss, arrInput, ',')) {
        std::istringstream numStream(arrInput);
        while (numStream >> num) {
            arr.push_back(num);
        }
    }

    if (arr.empty()) {
        std::istringstream spaceIss(arrInput);
        while (spaceIss >> num) {
            arr.push_back(num);
        }
    }

    return arr;
}
int main() {
    std::vector<int> arr = inputArr();
    int target;

    std::cout << "Input the target number: ";
    std::cin >> target;

    std::cout << jumpSearch(arr, target) << std::endl;

    return 0;
}