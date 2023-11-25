#include <iostream>
#include <list>

std::list<int> merge_lists(std::list<int>& list1, std::list<int>& list2){
   
    auto i = list1.begin();
    auto j = list2.begin();
    std::list<int> result;
    while (i != list1.end() && j != list2.end()) {
        if (*i <= *j) { 
            result.push_back(*i);
            ++i;
        } else {
            result.push_back(*j);
            ++j;
        }
    }
    while (i != list1.end()) {
        result.push_back(*i);
        ++i;
    }
    while (j != list2.end()) {
        result.push_back(*j);
        ++j;
    }
    return result;
}

int main(){
    std::list<int> list1 = { 1, 3, 5};
    std::list<int> list2 = { 2, 4, 7};

    std::list<int> mergedlist = merge_lists(list1, list2);
    if (!mergedlist.empty()) {
        std::cout << "Merged List 1: ";
        for (int num : mergedlist) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Merged List 1 is empty." << std::endl;
    }     
}