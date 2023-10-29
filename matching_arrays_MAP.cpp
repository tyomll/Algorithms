#include <iostream>
#include <map>
#include <string.h>

int sorting(int *array, int n){
    for(int i=1;i<n;i++){
    int arr=array[i];
    int j=i-1;
    while(j>=0 && array[j]>arr){
        array[j+1]=array[j];
        j--;
    }
    array[j+1]=arr;
}

/*for(int i=0;i<n;i++){
	std::cout<<std::endl;
	std::cout<<array[i]<<std::endl;}*/

    return  *array;
}

void insertMapPrint(std::string &A, int *array, int n){    
    std::map<char, int> mp;
    std::map<int, char> sp;
    int len=A.length();

    for(int i=0;i<len;i++){
        mp.insert({A[i], (int)A[i]});
    }
    int i=0;
    auto itr=mp.begin();
    while(i<n, itr!=mp.end()){
        std::cout<<'{'<<array[i]<<" "<<itr->first<<'}'<<std::endl;
        i++;
        itr++;
    }
}    
        

int main(){
    std::string A = "bedca";
    int n=5;
    int array[n]={2, 5, 4, 1, 3};
    sorting(array, n);
    insertMapPrint(A, array, n);

    return 0;
}