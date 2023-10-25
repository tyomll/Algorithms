#include <iostream>
#include <vector>

void printArr(int* arr, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "Array[" << i << "] = " << arr[i] << std::endl;
    }
}

int main() {
    int count;
    std::cout << "Count = ";
    std::cin >> count;
    int arr[count];
    for (int i = 0; i < count; i++) {
        std::cout << "Array[" << i << "] = ";
        std::cin >> arr[i];
    }
    int temp;

    for (int i = 1; i < count; ++i) { 
        for (int j = i - 1; j >= 0; --j) {
            if (arr[i] < arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                --i;
            }
        }
    }
    std::cout << "\nSorted\n\n";
    printArr(arr, count);

    return 0;
    
    
}