#include <iostream>
#include <list>

using namespace std;

template <typename T>
list<T> rotateList(list<T>& arr, int k) {
    if (arr.empty() || k == 0) {
        return arr;
    }

    for (int i = 0; i < k; i++) {
        T element = arr.back();
        arr.pop_back();
        arr.push_front(element);
    }
    return arr;
}

int main() {
    list<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    rotateList(arr, k);

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;

    return 0;
}

