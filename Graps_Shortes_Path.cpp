#include <iostream>
#include <vector>
#include <algorithm>
//#include <math.h>

#define INFINITY 1000000
#define V 5 //vertices

void DijkStras(int GrapH[V][V], int start){
    
    int Similar[V][V]; //create similar matrix to Graph[][];
    int distanses[V], pred[V]; // predecessor vertices;
    int unvisited[V], visited[V];
    int count, minDis, node;
    int  n=V;
    int number=start; // only for printing :)

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(GrapH[i][j]==0){
                Similar[i][j]=INFINITY;
            }
            else 
                Similar[i][j]=GrapH[i][j];
        }
    }

    for(int i=0;i<n;i++){
        distanses[i]=Similar[start][i];
        pred[i]=start;
        visited[i]=0;
        //unvisited[i]=i;
    }

    distanses[start]=0;
    visited[start]=1;
    count=1;
    while(count<n-1){
        minDis=INFINITY;
        for(int i=0;i<n;i++){
            if(distanses[i]<minDis && visited[i]!=1){
                minDis=distanses[i];
                node=i;
            }
        }
        visited[node]=1;
        for(int i=0;i<n;i++){
            if(visited[i]!=1){
                if(minDis+Similar[node][i]<distanses[i]){
                    distanses[i]=minDis+Similar[node][i];
                    pred[i]=node;
                }
            }
        }
        count++;
    }


// final printing table;
    int C = 3;
    int matx[V][C];
    for(int i=0; i<V; i++){
            matx[i][0]=i;  // vertices;
            matx[i][1]=distanses[i]; //shortest distanse;
            matx[i][2]=pred[i];      // pred. vertices;   
    }
    for(int i=0; i<V; i++){
        for(int j=0; j<C; j++){
            std::cout<<matx[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
std::cout<<"\t\t\tOR\n"<<std::endl;
std::cout<<"\t\ttable for vertices  "<<number<<"\n"<<std::endl;
std::cout<< "vertices"<<"\tshortest dist."<<"\tpred. vertices"<<std::endl;
for(int i=0; i<V; i++){
        for(int j=0; j<C; j++){
            std::cout<<matx[i][j]<<"\t\t";
        }
        std::cout<<std::endl;
    }

}




int main(){

    int E=5;//edges
    int start=2;
    int GrapH[V][V]={
        {0, 33, 11, 0, 66},
        {33, 0, 0, 44, 0},
        {11, 0, 0, 25, 0},
        {0, 44, 25, 0, 0},
        {66, 0, 0, 0, 0}
    };  

    DijkStras(GrapH, start);
    return 0;
}