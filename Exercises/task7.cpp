#include <iostream>
#include <vector>

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
std::pair<int, int> searchIndexes(std::vector<int>& arr, int target) {
    int index = ternarySearch(arr, target, 0, arr.size() - 1);
    if (index != -1) {
        int left = index;
        int right = index;
        while (arr[left] == target) {
            left--;
        }
        while (arr[right] == target) {
            right++;
        }

        return std::pair<int, int>(left + 1, right - 1);
    }
    
    return std::pair<int, int>(-1, -1);
}
void print(std::vector<int>& arr){
     for(int num : arr){
        std::cout << num << " ";
     }
     std::cout << std::endl;
}
int main(){
    std::vector<int> arr = {3, 7, 10, 13, 14, 46, 54};
    print(arr);
    int target;

    std::cout << "Enter the number you want to search: ";
    std::cin >> target;
    std::pair<int,int> result = searchIndexes(arr,target);
    std::cout << "[" << result.first << ", " << result.second << "]\n";
}
