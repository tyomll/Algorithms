#include <iostream>

int  searchGivenNumbersIndex(int *arr, int start, int end, int val){
     
     if(end>=start){
        int num1 = start + (end-start)/3;
        int num2 = end-(end-start)/3;
        if(arr[num1]==val){
            return num1;
        }
        if(arr[num2]==val){
            return num2;
        } 
        if(arr[num1]>val){
            return searchGivenNumbersIndex(arr, start, num1-1, val);
         }
         if(arr[num2]<val){
            return searchGivenNumbersIndex(arr, num2+1, end, val);
        }
            return searchGivenNumbersIndex(arr, num1+1, num2-1, val);
    }
     return -1;
}

int  main(){
    int n=12;
    int arr[n] ={-11, -5, 0, 2, 4, 11, 15, 22, 34, 55, 101, 111};
    int  val;
    std::cout<<"enter the number you want to  find:"<<std::endl;
    std::cin>>val;
    int start =0, end = n-1;
    int RES=searchGivenNumbersIndex(arr, start, end, val);
    std::cout<<"the index of number is: "<<'\t'<<RES<<std::endl;


    return 0;
}
