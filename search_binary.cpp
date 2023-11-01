#include <iostream>

int  searchGivenNumbersIndex(int *arr, int n, int val){
     int start = 0, end = n-1;
     int mid = start + (end-start)/2;
     do {
         if(arr[mid]==val){
        std::cout<<"the number's index is: "<<'\t'<<mid<<std::endl;
        break;
        } 
        if(arr[mid]>val){
            mid=start+((mid-1)-start)/2;
         }
        else {
            mid=(mid+1)+(end-mid+1)/2;
         }

     }
     while(start!=end);
     return -1;
}

int  main(){
int n=12;
int arr[n] ={-11, -5, 0, 2, 4, 11, 15, 22, 34, 55, 101, 111};
int  val;
std::cout<<"enter the number you want to  find:"<<std::endl;
std::cin>>val;
searchGivenNumbersIndex(arr, n, val);

    return 0;
}
