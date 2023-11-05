#include <iostream>

void FillArr(int arr[], int size) {
    for (int  i = 0; i < size; i++) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
    
}

void SortArr(int arr[], int size) {
    int min, index;
    for (int i = 0; i < size; i++) {
        min = arr[i];
        index = i;
        for (int j = i + 1; j < size; j++) {
            if (min > arr[j]) {
                min = arr[j];
                index = j;
            }
            
        }
        arr[i] = arr[i] + index;
        index = arr[i] - index;
        arr[i] = arr[i] - index;
        
    }
    

}
void PrintArr(int size, int arr[]) {
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    
}

int main() {
    int size;
    std::cout << "Enter the length of arr: ";
    std::cin >> size;
    std::cout << std::endl;
    int arr[size];
    FillArr(arr, size);
    SortArr(arr, size);
    PrintArr(size, arr);
    
    return 0;
}