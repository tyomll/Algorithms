#include<iostream>
#include<vector>

int interpolation_search (std::vector<int> array, int target, int low, int high) {
    if(target < array[low] && target > array[high]){
        return -1;
    }
    int pos = low + (target - array[low])*(high - low)/(array[high] - array[low]);
    if(target < array[pos]){
    return interpolation_search(array, target, low, pos-1);
    }
    else if(target >array[pos]) {
     return interpolation_search(array, target, pos+1, high);   
    }
    return pos;
}

int main(){
    std::vector<int> array = {10,20, 30, 40, 50};
    int target = 30;
    int result = interpolation_search(array, target, 0, array.size() - 1);
    if(result != -1){
    std::cout << "The index of target: " << result << "\n";
    }
    else {
        std::cout << "The target not found int tne array" << "\n";
    }
    return 0;
}
