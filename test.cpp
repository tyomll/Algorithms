#include <iostream>
#include <set>
#include <vector>

void insertSet(std::set<std::string>& obj, int count) {
    std::string value;
    for (int i = 1; i <= count; ++i) {
        std::cout << i << ". ";
        std::cin >> value;
        obj.insert(value);
    }
}

std::vector<std::string> addElements(std::set<std::string>& obj1, std::set<std::string>& obj2) {
    std::vector<std::string> result;
    auto firstSet = obj1.begin();
    auto secondSet = obj2.begin();
    while (firstSet != obj1.end()) {
        result.push_back(*firstSet + *secondSet);
        ++firstSet;
        ++secondSet;
    }
    
    return result;
}

int main() {
    std::set<std::string> ob1, ob2;
    std::vector<std::string> result;
    int count;
    std::cout << "Elements count = ";
    std::cin >> count;
    std::cout << "Enter the first array elements.\n";
    insertSet(ob1, count);
    std::cout << "\nNow enter the second array elements.\n";
    insertSet(ob2, count);
    std::cout << "\nSorted vector\n\n";
    result = addElements(ob1, ob2);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }
    
    return 0;
}