#include <iostream>
#include <climits>

using namespace std;

void printArray (int arr[],size_t size) {
    cout << "[";
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

int main () {
    int arr1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

    printArray(arr1, size1);

    int arr2[] = {5,4,-1,7,8};
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

    int start, end, maxSum;
    findMaxSubArray(arr1, size1, start, end, maxSum);

    cout << "Example 1: [" << start << ", " << end << "] with the sum " << maxSum << endl;

    printArray(arr2, size2);
    findMaxSubArray(arr2, size2, start, end, maxSum);
    cout << "Example 2: [" << start << ", " << end << "] with the sum " << maxSum << endl;

    return 0;
}
