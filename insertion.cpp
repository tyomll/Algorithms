#include <iostream>

int  main(){
int n;
std::cout<<"Etner the number of array"<<std::endl;
std::cin>>n;
int arr[n];
std::cout<<"Etner the elements:"<<std::endl;

for(int i=0;i<n;i++){
	std::cin>>arr[i];
}
// ---- insertion ------
for(int i=1;i<n;i++){
    int array=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>array){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=array;
}

for(int i=0;i<n;i++){
	std::cout<<std::endl;
	std::cout<<arr[i]<<std::endl;}

    return 0;
}