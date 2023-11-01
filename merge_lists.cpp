#include <iostream>
#include <map>

int main() {
        int array1[] =  {1, 2, 3}; 
        int size = sizeof(array1) / sizeof(array1[0]);

        std::map<int, char> CharMap = { 
                {1, 'a'}, {4, 'd'}, {3, 'c'}
        };
        for (int i = 0; i < size; i++) {
                if (CharMap.find(array1[i]) != CharMap.end()) {
                        std::cout << CharMap[array1[i]] << " ";
                }
        }

        std::cout << std::endl;


        return 0;
}

