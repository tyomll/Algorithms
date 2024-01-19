#include<iostream>
#include <vector>
std::vector<int>  merge(std::vector<int>& arr1, std::vector<int> arr2){
    std::vector<int> merged;
    int i = 0, j = 0;
     while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;

}
std::vector<int> mergesort(std::vector<int>& arr){
   int size = arr.size();
   if(size <= 1) {
    return arr;
   }
   int mid = size / 2;
   std::vector<int> left,right;
   for (int i = 0; i < mid; i++) {
    left.push_back(arr[i]);
   }
    for (int i = mid; i < size; i++) {
    right.push_back(arr[i]);
   }
   
   left = mergesort(left);
   right = mergesort(right);
   return merge(left, right);
}
void print(std::vector<int>& arr){
     for(int num : arr){
        std::cout << num << " ";
     }
     std::cout << std::endl;
}
int main(){

    std::vector<int> arr = {6, 1, 9, 2, 4, 5, 7, 8};
    
    std::cout << "Original array: ";
    print(arr);
    
    std::vector<int> merged_array = mergesort(arr);
    std::cout << "Merged array: ";
    print(merged_array);
    return 0;

}