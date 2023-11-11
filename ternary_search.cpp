#include<iostream>
#include<vector>

int ternary_search (std::vector <int> array, int target, int start, int end){\
    if(target < array[start] && target > array[end]){
        return -1;
    }
    int mid1 = start + (end - start) / 3;
    int mid2 = start + 2 * (end - start) / 3;
    if (target == array[mid1]) {
        return mid1;
    }

    else if(target == array[mid2]){
        return mid2;
    }

    if(target < array[mid1]){
        return ternary_search(array, target, start, mid1-1);
    }
    else if (target > array[mid2]){
        return ternary_search(array, target, mid2+1, end);
    }
    else{
        return ternary_search(array, target, mid1+1, mid2-1 );
    }
}

int main(){
    std::vector<int> array = {1,3,5,7,9,11};
    int target = 11;
    int result =  ternary_search(array, target, 0, array.size() - 1);
    if(result != -1){
    std::cout << "The index of target: " << result << "\n";
    }
    else {
        std::cout << "The target not found int tne array" << "\n";
    }
    return 0;
}