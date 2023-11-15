#include <iostream>
#include <vector>
#include <algorithm>



void addGraph(std::vector<int> vertices[], int s, int d){
    
    vertices[s].push_back(d);
    vertices[d].push_back(s);
}

void deleteEdges(std::vector<int> vertices[], const int s, const int d){

    /*for(int i=0;i<vertices[s].size();i++){
            if(vertices[s][i]==d){
                vertices[s].erase(i);
            }
        }*/
    std::vector<int>::iterator it=std::find(vertices[s].begin(), vertices[s].end(), d);
    vertices[s].erase(it);   
    it=std::find(vertices[d].begin(), vertices[d].end(), s);
    vertices[d].erase(it);  
    }


void print(std::vector<int> vertices[], int V){
    for(int i=0; i<V; i++){
        std::cout<<i<<"->"<<"{";
        for(auto it: vertices[i]){
            std::cout<<it<<" ";
        }
        std::cout<<"}"<<std::endl;
    }
    std::cout<<std::endl;
}


int main(){
    int V=5;
    int E=5;
    std::vector<int> vertices [100]; 
    
    addGraph(vertices, 0, 1);
    addGraph(vertices, 0, 2);
    addGraph(vertices, 0, 4);
    addGraph(vertices, 1, 3);
    addGraph(vertices, 2, 3);

    print(vertices, V);
    // add one more vertices
    V=V+1;
    addGraph(vertices, 5, 2);
    addGraph(vertices, 5, 3);
    print(vertices, V);

    deleteEdges(vertices, 1, 3);
    deleteEdges(vertices, 1, 0);

    print(vertices, V);
    //vertices[100].erase(vertices[100].begin()+1);

    return 0;
}