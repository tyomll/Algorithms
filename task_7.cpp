#include <iostream>
#include <vector>
#include <map>

int binary(std::vector<int> array, int target, int start, int end){
    
    if (target < array[0] || target > array[array.size() - 1]){
        return -1;
    }
     
    int mid = (start + end) / 2;

    if (target < array[mid]){
        return binary(array, target, start, mid - 1);
    }

    if (target > array[mid]){
        return binary(array, target, mid + 1, end);
    }

    return mid; 
}

std::map<int, int> search_index (std::vector<int> array, int target){
   
    int index  = binary(array, target, 0, array.size()-1);
    int left = index;
    int right = index;

    if(index != -1){
        for (int i=0; i < array.size(); ++i){
            if(array[i] == target) {
                left = i;
                break;
            }
        }

        for (int i = array.size() - 1; i >= 0; --i){
            if(array[i] == target){
                right = i;
                break;
            }
        }
    }

    return std::map<int, int> {{left, right}};

}

int main() {
    std::vector<int> array = {4, 5, 5, 8, 9, 10, 10};
    int target = 10;

    std::map<int, int> result = search_index(array, target);
    std::cout << "[" << result.begin()->first << ", " << result.begin()->second << "]" << "\n";

    return 0;
}