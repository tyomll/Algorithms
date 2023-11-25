#include <iostream>
#include <climits>
using namespace std;

void printArray (int arr[],size_t size) {
    cout << "The Original Array: [";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void findMaxSubArray (int arr[], size_t size, int &start, int &end, int &maxSum) {
    maxSum = INT_MIN, start = 0, end = 0;
    int tempStart = 0, currentSum = 0;

    for (int i = 0; i < size; i++) {
        currentSum += arr[i];

        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }   
    }
}

void printMaxSubArray(int arr[], int start, int end) {
    cout << "[";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main () {
    int arr1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {5, 4, -1, 7, 8};
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

    int start, end, maxSum;
    findMaxSubArray(arr1, size1, start, end, maxSum);

    printArray(arr1, size1);
    cout << "Array 1 with the sum " << maxSum << " ";
    printMaxSubArray(arr1, start, end);  

    cout << endl;

    printArray(arr2, size2);
    findMaxSubArray(arr2, size2, start, end, maxSum);
    cout << "Array 2 with the sum " << maxSum << " ";
    printMaxSubArray(arr2, start, end);

    return 0;
}
