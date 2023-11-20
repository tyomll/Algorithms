#include<iostream>
#include<vector>
#include<map>

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

std::map<int,int> searching(std::vector<int> array, int target){
    int left = -1, right = -1;
    int size = array.size();

    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            left = i;
            break;
        }
    }

    for (int i = size - 1; i >= 0; --i) {
        if (array[i] == target) {
            right = i;
            break;
        }
    }

     return std::map<int, int>{{left, right}};
}

int main() {
    std::vector<int> array = {2,4,5,6,6,8}; 
    int target = 6; 
    std::map<int, int> result = searching(array, target);
    for (const auto &pair : result) {
        std::cout << "[" << pair.first << " ; " << pair.second << "]\n";
    }
    return 0;
}
