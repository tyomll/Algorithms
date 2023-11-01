#include <iostream>

int main(){
int target = 35;
int n;
std::cout<<"Etner the number of array"<<std::endl;
std::cin>>n;
int arr[n];
std::cout<<"Etner the elements:"<<std::endl;
for(int i=0;i<n;i++){
	std::cin>>arr[i];
}

for(int i=0;i<n-1;++i){
    for(int j=1;j<n-2;++j){
        if(target == arr[i]+arr[j]){
            std::cout<<"["<<j<<","<<i<<"]"<<std::endl;
        }
    }
}
}