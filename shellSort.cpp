#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    
    for (int i = n / 2; i > 0; i /= 2) {
        for (int j = i; j < n; j++) {
            int temp = arr[j];
            int k;
            
            for (k = j; k >= i && arr[k - i] > temp; k -= i) {
                arr[k] = arr[k - i];
            }
            
            arr[k] = temp;
        }
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};
    int arrSize = arr.size();


    shellSort(arr);

    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

