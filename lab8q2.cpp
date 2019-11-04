//print then mark it as visited then find neighbours and call again


#include<iostream>
#include<queue>
using namespace std;

void dfs(int edges[][100],int n,int sv,int* visited){
    cout<<sv<<" ";
    visited[sv]=1;
    for(int i=0;i<n;i++){
        if(sv==i){
            continue;
        }
        else{
            if(edges[sv][i]==1 && visited[i]==0){
                dfs(edges,n,i,visited);
            }
        }
    }
}

int main(){
    int n,e,v,a1,b1;
    cout<<"enter edges and vertices";
    cin>>e;
    cin>>v;
    int a[100][100];
    int visited[100];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            a[i][j]=0;
        }
    }
    cout<<"enter the edges connections";
    for(int i=0;i<e;i++){
        cin>>a1;
        cin>>b1;
        a[a1][b1]=1;
        a[b1][a1]=1;
    }
    for(int i=0;i<v;i++){
        visited[i]=0;
    }
    int sv=0;
    dfs(a,v,sv,visited);

}
