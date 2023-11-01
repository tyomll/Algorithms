#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, const std::vector<int>& leftPart, const std::vector<int>& rightPart) {
    int leftSize = leftPart.size();
    int rightSize = rightPart.size();

    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (leftPart[i] <= rightPart[j]) {
            arr[k] = leftPart[i];
            i++;
        } else {
            arr[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftPart[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = rightPart[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr) {
    int arrLength = arr.size();

    if (arrLength < 2) {
        return;
    }

    int middle = arrLength / 2;
    std::vector<int> leftPart(middle);
    std::vector<int> rightPart(arrLength - middle);

    for (size_t i = 0; i < middle; i++) {
        leftPart[i] = arr[i];
    }
    for (size_t i = middle; i < arrLength; i++) {
        rightPart[i - middle] = arr[i];
    }

    mergeSort(leftPart);
    mergeSort(rightPart);

    merge(arr, leftPart, rightPart);
}

int main() {
    std::vector<int> arr = {4, 1, 5, 0, 8, 15, -55};

    mergeSort(arr);

    for (const int& el : arr) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}