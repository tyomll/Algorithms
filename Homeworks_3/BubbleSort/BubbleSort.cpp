#include <iostream>
#include <vector>

template <typename T>
class BubbleSort {
private:
    std::vector<T>& array;
public:
    BubbleSort(std::vector<T>& arr) : array(arr) {
        int n = array.size();
        bool swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    std::swap(array[j], array[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }

    void print() {
        std::cout << "{ ";
        for (const T& element : array) {
            std::cout << element << ", ";
        }
        std::cout << "\b\b }\n";
    }
};

int main() {
    std::vector<int> intArray{5, 4, 8, 2, 1, 3, 7, 9, 10, 6};
    std::vector<char> charArray{'b', 'd', 'a', 'e', 'f', 'g', 'i', 'o', 'm', 't'};

    BubbleSort<int> intSorter(intArray);
    intSorter.print();

    BubbleSort<char> charSorter(charArray);
    charSorter.print();

    return 0;
}
