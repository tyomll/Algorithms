#include <iostream>
#include <cmath>


int searchTargetIndex(int* arr, int n, int val){
    //searching target index with exponential method
    int m=2;
    int  i=0;
    if(arr[m]==val){
        return m;
    }
    while(m<n && arr[m]<val){
        i=m;
        m=m*2;
        if(arr[m]==val){
            return m;
        }
        if(m>n-1){
            return -1;
        }
    } 
    //line search 
    for(int j=i;j<m;j++){
        if(arr[j]==val){
            return j;
        }
    }
    return -1;
}




int  main(){

int n, target, RES;
std::cout<<"How many  elements do you want to  enter? "<<std::endl;
std::cin>>n;
int *arr = new int[n];
std::cout<<"Etner the elements:"<<std::endl;

for(int i=0;i<n;i++){
	//std::cin>>arr[i];
    while(!(std::cin>>arr[i])){
        std::cout<<"ERORR! enter the number!"<<std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
}
if(arr[0]==NULL){
    std::cout<<"the array  is already empty! Try again!"<<std::endl;
    exit(-1);
}
    std::cout<<"Enter the element you want to  find: "<<std::endl;
    std::cin>>target;
    RES = searchTargetIndex(arr, n, target);
    if(RES==-1){
        std::cout<<"the element didn't find"<<std::endl;
    }
    if(RES!=-1){
        std::cout<<RES<<std::endl;
    }
    delete [] arr;
    
    return 0;
}
