#include <iostream>
#include <vector>

int k_th_max(std::vector<int>& arr, int k) {
    int max = 0;
    while (k > 0) {
        int i = 0, j = 0;
        max = arr[i];
        while (i < arr.size()) {
            if (arr[i] > max) {
                max = arr[i];
                j = i;
            }
            i++;
        }
        arr.erase(arr.begin() + j);
        k--;
    }
    return max;
}

int main() {
    std::vector<int> arr = {3, 2, 1, 5, 6, 4};
    int max = k_th_max(arr, 3);
    std::cout << max << std::endl;
    return 0;
}
