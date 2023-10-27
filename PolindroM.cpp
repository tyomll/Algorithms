#include <iostream>

void polindrom(int n, int *arr){
for(int i=0;i<n;i++){
    int reverse=0, rem, temp;
    temp=arr[i];
    while(temp!=0){
        rem=temp%10;
        reverse=reverse*10+rem;
        temp/=10;
    }
    if(reverse==arr[i]){
        std::cout<<arr[i]<<std::endl;
    }
}
}

int  main(){
int n;
std::cout<<"Etner the size of array"<<std::endl;
std::cin>>n;
int arr[n];
std::cout<<"Etner the elements:"<<std::endl;

for(int i=0;i<n;i++){
	std::cin>>arr[i];
}
std::cout<<"\nThe palindroms are: "<<std::endl;
polindrom(n, arr);
    return 0;
}