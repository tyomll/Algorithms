#include <iostream>
#include <vector>

void print_arr(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Array[" << i << "] = " << arr[i] << std::endl;
    }
}

std::vector<int> merge_sort(const std::vector<int>& array1, const std::vector<int>& array2) {
    int i = 0;
    int j = 0;
    std::vector<int> result;
    while (i < array1.size() && j < array2.size()) {
        if (array1[i] < array2[j]) {
            result.push_back(array1[i]);
            ++i;
        }
        else {
            result.push_back(array2[j]);
            ++j;
        }
    }

    while (i < array1.size()) {
        result.push_back(array1[i]);
        ++i;
    }
    
    while (j < array2.size()) {
        result.push_back(array2[j]);
        ++j;
    }

    return result;
    
}

std::vector<int> merge_Sort(const std::vector<int>& array) {
    int arrSize = array.size();
    if (arrSize <= 1) {
        return array;
    }
    std::vector<int> leftArray, rightArray;
    for (int i = 0; i < arrSize / 2; ++i) {
        leftArray.push_back(array[i]);
    }
    for (int j = arrSize / 2; j < arrSize; ++j) {
        rightArray.push_back(array[j]);
    }

    leftArray = merge_Sort(leftArray);
    rightArray = merge_Sort(rightArray);
    return merge_sort(leftArray, rightArray);
    
}

int main() {
    std::vector<int> array = {5, 2, 0, -6, 12, 63};
    std::vector<int> result = merge_Sort(array);
    print_arr(result);

    return 0;
}