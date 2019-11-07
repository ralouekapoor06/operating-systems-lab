#include<iostream>
using namespace std;

int minkey(int key[],bool mstset[]){
    int min=999,minindex;
    for(int j=0;j<5;j++){
        if(mstset[j]==false && key[j]<min){
            min=key[j];
            minindex=j;
        }
    }
    return minindex;
}

void primsMST(int graph[5][5]){
    int parent[5];
    bool mstset[5];
    int key[5];
    for(int i=0;i<5;i++){
        mstset[i]=false;
        key[i]=999;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<5-1;i++){
        int u=minkey(key,mstset);
        mstset[u]=true;
        for(int v=0;v<5;v++){
            if(graph[u][v]!=0 && mstset[v]==false && graph[u][v]<key[v]){
            key[v]=graph[u][v];
            parent[v]=u;
        }
        }   
    }
     for (int i = 1; i < 5; i++)
            printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

int main(){
    int graph[5][5] = { { 0, 2, 0, 6, 0 }, { 2, 0, 3, 8, 5 },{ 0, 3, 0, 0, 7 }, { 6, 8, 0, 0, 9 }, { 0, 5, 7, 9, 0 }};
    primsMST(graph);
}