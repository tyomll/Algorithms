#include <iostream>
#include <vector>

void newArr(std::vector<int>& Vector, int elements_count) {
    int numbers;
    for (int i = 0; i < elements_count; ++i) {
        std::cout << "arr[" << i << "]";
        std::cin >> numbers;
        Vector.push_back(numbers);
    } 
}

int main() {
    std::vector<int> Vector, result;
    int elements_count;
    std::cout << "Size of Vector: ";
    std::cin >> elements_count;
    std::cout << "Elements of that Vector: " << std::endl;
    newArr(Vector , elements_count);
    int reversedNum = 0, remainder, num;
    for (int i = 0; i < elements_count; ++i) {   
        num = Vector[i];
        while (num != 0) {
            remainder = num % 10;
            reversedNum = reversedNum * 10 + remainder;
            num /= 10;
        }
        if (Vector[i] == reversedNum) {
            result.push_back(Vector[i]);
        }
        reversedNum = 0;
    }
    std::cout << "The palindrom numbers are:  ";
    for (int j = 0; j < result.size(); ++j) {
        std::cout << result[j] << ", ";
    }
    std::cout << std::endl;
    return 0;
}
