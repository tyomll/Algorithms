#include<iostream>
#include<vector>
int ternarySearch(std::vector<int>& arr,int target,int left,int right){
    if ( left <= right ){
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if ( target == arr[mid1] ){
        return mid1;
    } else if ( target == arr[mid2] ){
        return mid2;
    } else if ( target < arr[mid1] ){
        return ternarySearch(arr, target, left, mid1 - 1);
    } else if ( target > arr[mid2] ){
        return ternarySearch(arr, target, mid2 + 1, right);
    } else {
        return ternarySearch(arr, target, mid1 + 1, mid2 - 1);
    }
    }
    return -1;

}
int main(){
    std::vector<int> arr = {3, 7, 9, 14, 25, 46, 54};
    int target;

    std::cout << "Enter the number you want to search: ";
    std::cin >> target;

    int result = ternarySearch(arr, target, 0, arr.size() - 1);

    if (result == -1) {
        std::cout << "Element not found" << std::endl;
    } else {
        std::cout << "Element found at index: " << result << std::endl;
    }

    return 0;

}