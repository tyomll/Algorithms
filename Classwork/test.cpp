#include <iostream>

int main() {
    int a[4] = {2,7,11,15};
    const int target = 9;
    for (int i = 0; i < 4 - 1; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (a[i] + a[j] == target) {
                std::cout << "[" << i << ", " << j << "]" << std::endl;
                break;
            }
        }
    }
    
    return 0;
}