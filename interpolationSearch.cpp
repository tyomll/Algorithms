#include <iostream>

int interpolationSearch(int target, int arr[], int higth, int low = 0){
    int pos = low + (higth - low) * (target - arr[low]) / (arr[higth] - arr[low]);
    if (arr[pos] == target) {
        return pos;
    }

    if (arr[pos - 1] == target) {
        return pos - 1;
    }
    
    if (arr[pos + 1] == target) {
        return pos + 1;
    }

    if (target > arr[pos]) {
        interpolationSearch(target, arr, higth, pos + 1);
    }

    if (target < arr[pos]) {
        interpolationSearch(target, arr, pos - 1, low);
    }
    
    return -1;
}

template <typename T>
void inputArr(int arr[], int size) {
    for (int i = 0;i < size;i++) {
        T elem;
        std::cin >> elem;
        int type = CheckType(elem);
        if (type == 0){
            arr[i] = elem;
        }
        else {
            std::cerr << "Input intagers!!!" << std::endl;
            i--;
        }
    }
}

template <typename T>
int CheckType(const T& element) {
    if (std::is_same<T, int>::value) {
        return 0;
    }
     else {
        return -1;
    }
}

int main (){
    int size;
    std::cout << "input the length: ";
    std::cin >> size;

    if (size == 0) {
        std::cerr << "Array is empty" << std::endl;
        return -1;
    }
    int arr[size];
    std::cout << "Input the array: ";
    inputArr(arr, size);

    int target;
    std::cout << "Input the target: ";
    std::cin >> target;


    int result =  interpolationSearch(target, arr, size - 1, 0);

    if (result == -1){
        std::cout << "The element not found in array!!" << std::endl;
    }
    else  {
        std::cout << "The index of the number is: " << result << std::endl;
    }
    
    
    return 0;
}
