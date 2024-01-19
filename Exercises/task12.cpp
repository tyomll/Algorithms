#include <iostream>
#include <list>

std::list<int> sorted_list(std::list<int>& list){
    int size = list.size();
    std::list<int> sortedlist;
    
    for(int i = 0; i < size; i++){
        auto min = list.begin();
        for(auto it = ++list.begin(); it != list.end(); it++){
            if(*min > *it){
                min = it; 
            }
        }
        list.erase(min);
        sortedlist.push_back(*min);
    }
    return sortedlist;
}
void print(std::list<int> list){
    for(auto it : list){
        std::cout << it << " ";
    }

}

int main(){
    std::list<int> list = {4, 2, 7, 5, 3};
    std::cout << "The given array is: ";
    
    print(list);
    std::list<int> resault = sorted_list(list);
    std::cout << std::endl;
    std::cout << "The sorted array is: ";
    print(resault);
    
}