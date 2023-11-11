#include<iostream>
#include<vector>


int binary_search(std::vector<int> array, int target, int start, int end) {
    if(target < array[start] && target > array[end]){
        return -1;
    }
    int mid = (start+end)/2;
    if (target == array[mid]) {
        return mid;
    } else if (target < array[mid]) {
        return binary_search(array, target, start, mid - 1);
    } else {
        return binary_search(array, target, mid + 1, end);
    }
}

int main(){
    std::vector<int> array = {2 ,4, 6, 8, 10};
    int target = 10;
    int result =  binary_search(array, target, 0, array.size() - 1);
    if(result != -1){
    std::cout << "The index of target: " << result << "\n";
    }
    else {
        std::cout << "The target not found int tne array" << "\n";
    }
    return 0;
}

