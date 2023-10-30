#include <iostream>

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

// ---- selection ------
void selection(int *arr, int n){
    int min_index;
    for(int i=0;i<n-1;i++){
        min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }    
        }
        swap(&arr[min_index], &arr[i]);
    }
    for(int i=0;i<n;i++){
	std::cout<<std::endl;
	std::cout<<arr[i]<<std::endl;
    }
}

int  main(){
int n;
std::cout<<"Etner the number of array"<<std::endl;
std::cin>>n;
int arr[n];
std::cout<<"Etner the elements:"<<std::endl;

for(int i=0;i<n;i++){
	std::cin>>arr[i];
}

selection(arr, n);
//print(arr, n);

    return 0;
}
