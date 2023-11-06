#include <iostream>

void insertArr(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}

int main() {
    int count, target;
    std::cout << "Enter elements count: ";
    std::cin >> count;
    int arr[count];
    insertArr(arr, count);
    std::cout << "\nNow enter the target: ";
    std::cin >> target;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (arr[i] + arr[j] == target) {
                std::cout << "[" << i << ", " << j << "]" << std::endl;
                break;
            }
        }
    }
    
    return 0;
}