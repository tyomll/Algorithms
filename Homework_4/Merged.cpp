#include <iostream>
#include <vector>

void printArr(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Array[" << i << "] = " << arr[i] << std::endl;
    }
}

std::vector<int> merge(const std::vector<int>& array1, const std::vector<int>& array2) {
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

std::vector<int> mergeSort(const std::vector<int>& array) {
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

    leftArray = mergeSort(leftArray);
    rightArray = mergeSort(rightArray);
    return merge(leftArray, rightArray);
    
}

int main() {
    std::vector<int> array = {6, 1, 0, 10, 8, 56};
    std::vector<int> result = mergeSort(array);
    printArr(result);

    return 0;
}