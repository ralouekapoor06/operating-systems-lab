//push in stack,make it visited,print it and pop it

#include<iostream>
#include<queue>
using namespace std;

void bfs(int edges[][100],int n,int sv,int* visited){
    queue<int>q;
    q.push(sv);
    visited[sv]=1;
    while(q.empty()==false){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        for(int i=0;i<n;i++){
            if(visited[i]==1){
                continue;
            }
            else if(edges[x][i]==1){
                q.push(i);
                visited[i]=1;
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
    bfs(a,v,sv,visited);

}
