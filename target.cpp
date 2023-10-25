#include <iostream>

void find_sum(int arr[], int size, int target, int& index1, int& index2) {

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] + arr[j] == target) {
                index1 = i;
                index2 = j;
                return;
            }
        }
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int array[size];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    int target;
    std::cout << "Enter the target sum: ";
    std::cin >> target;

    int index1 = 0;
    int index2 = 0;

    find_sum(array, size, target, index1, index2);

    if (index1 != 0 || index2 != 0) {
        std::cout << "Result: [" << index1 << ", " << index2 << "]" << std::endl;
    } else {
        std::cout << "No pair found with the target sum." << std::endl;
    }

    return 0;
}
