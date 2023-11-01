#include <iostream>
#include <list>

void listt_sum(std::list<int>& A, std::list<int>& B){
    std::list<int> C;
        for(auto a=A.begin(), b=B.begin(); a != A.end() && b != B.end(); ++a, ++b) {
        C.push_back(*a + *b);
    }

    for(auto &i: C) {
        std::cout<< i <<std::endl;
    }
}

int  main(){

    std::list<int> A = { 1, 5, 6 };
    std::list<int> B = { 9, 8, 7 };
  
    A.size();
    listt_sum(A, B);
    //print(C);

return 0; 
}
