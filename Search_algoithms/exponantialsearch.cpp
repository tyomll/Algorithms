#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target){
        return mid;
    } else if (arr[mid] > target) {
        return binarySearch(arr, target ,left, mid - 1);
    } else {
        return binarySearch(arr, target, mid + 1, right);
    }
}

int exponantialSearch(std::vector<int>& arr,int target){

    if(arr[0] == target){
        return 0;
    }
    int i=1;
    while( i < arr.size() && arr[i] <= target )
        i = i * 2;
        binarySearch(arr, target, i / 2, std::min(i, static_cast<int>(arr.size() - 1)));
    


}

int main(){
    std::vector<int> arr = {3, 6, 9, 12, 25, 37, 45, 56};
    int target;

    std::cout << "Enter the number you want to search: ";
    std::cin >> target;

    int result = exponantialSearch(arr, target);
    if (result == -1) {
        std::cout << "Element not found" << std::endl;
    } else {
        std::cout << "Element found at index: " << result << std::endl;
    }
    return 0;
}