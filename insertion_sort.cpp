#include <iostream>

int main() {
    int i, n;
    std::cout << "n=";
    std::cin >> n;
    int a[n], j;

    for (i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (i = 0; i < n; i++) {
        int temp = a[i];
        j = i-1;
        
        while (j>=0 && a[j] > temp){
            a[j+1] = a[j];
            j--;
        }
        
            a[j+1] = temp;
    }

    for (i = 0; i < n; i++) {
        std::cout << a[i] << "\t";
    }
    std::cout<<"\n";
    return 0;
}

