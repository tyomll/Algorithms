#include <iostream>
#include <set>
#include <vector>

int main() {
    std::set<int> numbers;
    std::set<std::string> letters;
    int n,number;
    std::string letter;
    std::cout<<"Enter the number of elements : ";
    std::cin >> n ;
    std::cout<< "enter the numbers : " ;
    for( int i=0;i<=n;i++){
        std :: cout << i +1 << ":";
        std::cin >> number ;
        numbers.insert(number);
    }
    std::cout<< "enter the letters: " ;
    for( int i=0;i<=n;i++){
        std :: cout << i << ":";
        std::cin >> letter;
        letters.insert(letter);
    }
     std::vector<std::string> Vector;
    
    auto firstnumber = numbers.begin();
    auto firstletter = letters.begin();

    while (firstnumber != numbers.end() && firstletter != letters.end()) {
        Vector.push_back(*firstletter + std::to_string(*firstnumber));
        ++firstnumber;
        ++firstletter;
    }

    std::cout << "Combined elements in the vector: ";
    for (const std::string& element : Vector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
