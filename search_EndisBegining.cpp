#include <iostream>


int  searchAnomal(int *arr,  int n){
    //at first find  the breaktrough element,  to divide the array  into to  parts
      int start =0;
      int end = n-1;
      do {
    
        int mid = start+(end-start)/2;
        //std::cout<<mid<<std::endl;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            return mid+1;
            
        }
        if(arr[mid-1]>arr[mid] && arr[mid]<arr[mid+1]){
            return mid;
        }
      
        if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
            if(arr[mid]>arr[0]){
                start=mid+1;
            }
            if(arr[mid]<arr[0]){
                end=mid-1;
            }
        }
    }
    while(start<=end);
    return 0;
}

int  searchGivenNumbersIndex(int *arr, int n, int index, int target){
    //search  index with binary method in two parts of  array separatly. 
        int start=0;
        int  end =index-1;
        do{
            int mid = start+(end-start)/2;
            if(arr[mid]==target){ 
                return mid;
            } 
            if(arr[mid]>target){
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        while(start<=end);
    // second part    
        start=index;
        end=n;
        do{
            int mid = start+(end-start)/2;
            if(arr[mid]==target){ 
                return mid;
            } 
            if(arr[mid]>target){
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
int arr[n] ={49, 55, 101, 111, 115, 120, 123, 5, 8, 11, 15, 22, 34};
int  val;
std::cout<<"enter the number you want to  find:"<<std::endl;
//std::cin>>val;
 while(!(std::cin>>val)){
        std::cout<<"ERORR! enter the number!"<<std::endl;
        std::cin.clear();
        std::cin.ignore();
    }

int anomal=searchAnomal(arr, n);
int RES=searchGivenNumbersIndex(arr, n, anomal, val);
if(RES==-1){
    std::cout<<"the number not found!"<<std::endl;
}
else{
    std::cout<<"the number's index is: "<<'\t'<<RES<<std::endl;
}
    return 0;
}
