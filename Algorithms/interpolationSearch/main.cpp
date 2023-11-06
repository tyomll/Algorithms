#include <iostream>
#include <sstream>
#include <vector>

int interpolationSearch(const std::vector<int>& arr, const int& target) {
    int low = 0, high = arr.size() - 1;
    int index =
        low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

    return arr[index] == target
               ? index
               : index + 1 +
                     ((target - arr[index + 1]) * (high - index + 1)) /
                         (arr[high] - arr[index + 1]);
}
std::vector<int> inputArr() {
    std::vector<int> arr;

    std::string arrInput;
    std::cout << "Enter a array of space-separated values: ";

    std::getline(std::cin, arrInput);
    std::istringstream iss(arrInput);
    int num;

    while (iss >> num) {
        arr.push_back(num);
    }

    return arr;
}
int main() {
    std::vector<int> arr = inputArr();
    int target;

    std::cout << "Input the target number: ";
    std::cin >> target;

    std::cout << "Index of target number - " << interpolationSearch(arr, target)
              << std::endl;

    return 0;
}