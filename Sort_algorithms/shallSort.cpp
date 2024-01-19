#include <iostream>
#include <vector>


std::vector<int> insertionSort(std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }

        vec[j + 1] = key;
    }
    return vec;
}

void shellsort(std::vector<int>& arr) {
    int n = arr.size() / 2;
    while (n >= 1) {
        for (int i = 0; i < arr.size() - n; i++) {
            if (arr[i] > arr[i + n]) {
                std::swap(arr[i], arr[i + n]);
            }
        }
        n /= 2;
    }
    arr = insertionSort(arr);
}
void print(std::vector<int>& arr){
     for(int num : arr){
        std::cout << num << " ";
     }
     std::cout << std::endl;
}
int main(){

    std::vector<int> arr = {15, 2, 34, 23, 6, 54, 21};
    
    std::cout << "Original array: ";
    print(arr);
    
    shellsort(arr);
    std::cout << "Sorted array: ";
    print(arr);
    return 0;

}