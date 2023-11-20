#include <iostream>
//#include <vector>

void sort(int A[], int N){
    for(auto i=1;i<N;i++){
    int array=A[i];
    int j=i-1;
    while(j>=0 && A[j]>array){
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=array;
    }
}

int find_K_th_largest(int arr[], int n, int K){
    
    //create new range from  fisrt K elements;
    int range[K];
    for(int i=0;i<K;i++){
        range[i]=arr[i];
    }
    
    //sort only new range;
    sort(range, K);

    //compare rest  elements with max. of range;
    for(int i=K;i<n;i++){
        if(arr[i]>range[0]){
            range[0]=arr[i];
            sort(range, K);
        }
    }
    return range[0];
}


int  main(){
int n=12;
int arr[n] ={9, 22, 101, 11, 115, 12, 123, 5, 8, 113, 55, 28, 34};
int  K=4;
std::cout<<"\nthe given array is:"<<"\n{";
for(int i=0;i<n;i++){
    std::cout<<arr[i]<<"  ";
}
std::cout<<"}"<<std::endl;
std::cout<<"\n"<<K<<"-th larg element is: "<<std::endl;
int M=find_K_th_largest(arr, n, K);
std::cout<<M<<std::endl;
    return 0;
}
