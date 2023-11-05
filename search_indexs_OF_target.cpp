#include <iostream>

int* searchTargetIndex(int *arr, int n, int target){
    //function return all indexs of target//
    int i, count = 0;
    int index1; //index2;
    int* array=new int[2];
    for( i=0; i<=n-1;++i){
        if(arr[i]==target){
            array[0]=i;
            index1=i;
            count++;
        break;
        }  
    if(arr[i]!=target){
        array[0]=-1;
        array[1]=-1;
    }
    }
    if(count!=0){
        for(i=index1+1;i<=n-1;++i){
            if(arr[i]!=target){
            array[1]=i-1;
            //index2=i-1;
            break;
            }
        }
    
   
    }

    return array;
}

int  main(){
int n=8;
int arr[n] ={-5, 0, 11, 15, 15, 15, 55, 101};
int target=15;
int* Arr={searchTargetIndex(arr, n, target)};

std::cout<<'[';
for(int i=0;i<2;i++){
    std::cout<<Arr[i]<<" ";
}
    std::cout<<']'<<std::endl;
    delete [] Arr;
    return 0;
}
