#include <iostream>
#include <list>


 void join(std::list<int> L1, std::list<int> L2){
      for(auto i=L2.begin(); i!=L2.end();i++ ){
            L1.push_back(*i); 
        }

//----sorting  joined lists-----//
// --------selection ----------//

std::list<int>::iterator i;
for(i=L1.begin();i!=(--L1.end());++i){
    int* min=&(*i);
    std::list<int>::iterator j=i;
    ++j;
        for(;j!=L1.end(); ++j){
             if(*min>*j){
            min=&(*j);
             }
        }
    int temp=*i;
    *i=*min;
    *min=temp;
}
    for(auto &i: L1) {
        std::cout<< i <<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<*L1.begin()<<std::endl;

}

int  main(){
    std::list<int> L1={1,9,6,7};
    std::list<int> L2={2,8,5,3,10};
    join(L1, L2);   

    return 0;
}