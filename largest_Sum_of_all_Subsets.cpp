#include <iostream>
#include <cmath>
#include <vector>
#include <map>

void Subset(int *arr, int  n){
        //the conut all subsets will be 2^n;
        int N=pow(2, n);
        std::vector<int> subset;
        std::map<int, std::vector<int>> mp;
        for(int i=0;i<N;i++){
                int Sum=0;
                // count the sum of each subset;
                for(int j=0;j<n;j++){
                    if(i&(1<<j))
                        Sum+=arr[j];
                }   
                // insert each subset into vector;
                for(int j=0;j<n;j++){
                    if(i&(1<<j))
                        subset.push_back(arr[j]);
                }   
                //insert each subset and it's sum into map;         
                mp[Sum]=subset;
                subset.clear();  
        }
        std::cout<<"\nThe map is:"<<std::endl;
        for(auto p:mp){
                std::cout<<p.first<<" "<<"{";
                for(int d:p.second){
                        std::cout<<d<<" ";
                }
                std::cout<<"}"<<std::endl;
         }
        //RETURN THE MAX SUM AND HER SUBSET!;
        std::cout<<"\nthe largest sum of all subsets and the subset are: "<<std::endl;
        std::map<int, std::vector<int>>::iterator itr=mp.end();
        itr--;
        std::cout<<itr->first<<"  {";
        for(std::size_t i=0;i<itr->second.size();i++){
                std::cout<<itr->second[i]<<" ";
        }
        std::cout<<"}\n"<<std::endl;
}

int main(){
        size_t n=4;
        int* arr = new int[4];
        std::cout << "enter the set:" << std::endl;
for(int i=0;i<n;i++){
                std::cin >> arr[i];}
        std::cout << "{";
for(int i=0;i<n;i++){
        std::cout << arr[i] << " ";}
        std::cout << "}";
        std::cout << std::endl;
        Subset(arr, n);
delete arr;
arr=NULL;
return 0;
}
