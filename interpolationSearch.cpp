#include <iostream>
#include <type_traits>
#include <stdexcept>

void clearInputBuffer() {
    while (std::cin.get() != '\n') {
        continue;
    }
}

int interpolationSearch(int target, int arr[], int high, int low = 0) {
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((double)(target - arr[low]) / (arr[high] - arr[low])) * (high - low);
        
        if (arr[pos] == target) {
            return pos;
        }

        if (arr[pos] < target) {
            low = pos + 1;
        } 

		else {
            high = pos - 1;
        }
    }

    return -1;
}

template <typename T>
void inputArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        try {
            T elem;
            std::cin >> elem;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cerr << "Invalid input. Please enter integers." << std::endl;
                clearInputBuffer();
                i--;
            }
			else {
                arr[i] = elem;
            }
        } 
		catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            i--;
        }
    }
}

int main() {
    int size;
    std::cout << "Input the length: ";
    std::cin >> size;

    if (size <= 0) {
        std::cerr << "Array size must be a positive integer." << std::endl;
        return -1;
    }

    int arr[size];
    std::cout << "Input the array: ";
    inputArr<int>(arr, size);

    int target;
    std::cout << "Input the target: ";
    try {
        std::cin >> target;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cerr << "Invalid input for the target. Please enter an integer." << std::endl;
            clearInputBuffer(); 
            return -1;
        }

        int result = interpolationSearch(target, arr, size - 1, 0);

        if (result == -1) {
            std::cout << "The element was not found in the array." << std::endl;
        } else {
            std::cout << "The index of the number is: " << result << std::endl;
        }
    }
	catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}

