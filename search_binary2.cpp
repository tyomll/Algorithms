#include <iostream>

int  searchGivenNumbersIndex(int *arr, int n, int val){
     int start = 0;
     int end = n-1;
     
     do {
        int mid = start + (end-start)/2;
         if(arr[mid]==val){ 
            return mid;
        } 
        if(arr[mid]>val){
            end=mid-1;
         }
        else {
            start=mid+1;
         }

     }
     while(start<=end);
        return -1;
}

int  main(){
int n=12;
int arr[n] ={-11, -5, 0, 2, 4, 11, 15, 22, 34, 55, 101, 111};
int  val;
std::cout<<"enter the number you want to  find:"<<std::endl;
std::cin>>val;
int RES=searchGivenNumbersIndex(arr, n, val);
if(RES==-1){
    std::cout<<"the number not found!"<<std::endl;
}
else{
    std::cout<<"the number's index is: "<<'\t'<<RES<<std::endl;
}
    return 0;
}
