#include <iostream>
#include <list>


void rotateArray(std::list<int> arr, int n, int k){
    int count=0;
    int a;
    //auto it=arr.back();
    //std::cout<<it<<std::endl;
    while(count<k){
        a=arr.back();
        arr.push_front(a);
        arr.pop_back();
        count++; 
    }
    std::cout<<"\nk="<<k<<std::endl;

    std::cout<<"\nThe array after rotating!\n"<<'[';
    std::list<int>::iterator it;
    for(it=arr.begin();it!=arr.end();it++){
    std::cout<<*it<<" ";
}
    std::cout<<']'<<std::endl;
}

int  main(){
int n=8;
std::list<int> arr={1, 5, 11, 15, 18, 21, 55, 101};
int k=5;

//print inital array;
std::cout<<"\nThe array before rotating!\n"<<'[';
std::list<int>::iterator it;
for(it=arr.begin();it!=arr.end();it++){
    std::cout<<*it<<" ";
}
std::cout<<']'<<std::endl;

rotateArray(arr,n,k);

    return 0;
}
