#include <iostream>
#include <vector>

void swap(std::vector<int>& arr, int first, int second) {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void quickSort(std::vector<int>& arr, int lowIndex, int highIndex) {
    if (lowIndex >= highIndex) {
        return;
    }

    int pivot = arr[highIndex];

    int leftPointer = lowIndex, rightPointer = highIndex;

    while (leftPointer < rightPointer) {
        if (arr[leftPointer] <= pivot && leftPointer < rightPointer) {
            leftPointer++;
        }
        if (arr[rightPointer] >= pivot && leftPointer < rightPointer) {
            rightPointer--;
        }

        swap(arr, leftPointer, rightPointer);
    }

    swap(arr, leftPointer, highIndex);

    quickSort(arr, lowIndex, leftPointer - 1);
    quickSort(arr, leftPointer + 1, highIndex);
}

void quickSort(std::vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

int main() {
    std::vector<int> arr = {4, 1, 5, 0, 8, 15, -55};

    quickSort(arr);

    for (const int& el : arr) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}