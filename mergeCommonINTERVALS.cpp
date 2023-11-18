#include <iostream>
#include <map>
#include <vector>

void merge(std::map<int,int> MP, int n){
    //at first take elements from map into two vectors.
    std::vector<int> arrFirst;
    std::vector<int> arrSecond;
    for(auto it:MP){
        arrFirst.push_back(it.first);
        arrSecond.push_back(it.second);
    }
    
    //compare elements from second vector to first's.
    //delete  elemets of the intersecting range.

    for(auto i=0;i<n;i++){
        if(arrSecond[i]>arrFirst[i+1] && arrSecond[i]<arrSecond[i+1]){
            arrSecond.erase(arrSecond.begin()+i);
            arrFirst.erase(arrFirst.begin()+(i+1));
        }

        if(arrSecond[i]==arrFirst[i+1]){
            arrSecond.erase(arrSecond.begin()+i);
            arrFirst.erase(arrFirst.begin()+(i+1));
        }
    }
    MP.clear();
    
    // print new ranges that's  start and end numbers are elements from first and second vectors.
    std::cout<<"\nThe new ranges are: "<<std::endl;
    for(auto i=0;i<arrFirst.size();i++){
        std::cout<<"{"<<arrFirst[i]<<","<<arrSecond[i]<<"}"<<std::endl;
    }   
}

int  main(){
    int n=4;
    std::map<int,int> mp;
    mp.insert(std::pair<int,int>(1,4));
    mp.insert(std::pair<int,int>(4,5));
    mp.insert(std::pair<int,int>(7,10));
    mp.insert(std::pair<int,int>(15,18));
   
    std::cout<<"\nThe given ranges are: "<<std::endl;
    for(auto it:mp){
        std::cout<<"{"<<it.first<<","<<it.second<<"}"<<std::endl;
    }
    merge(mp, n);
    
        return 0;
}