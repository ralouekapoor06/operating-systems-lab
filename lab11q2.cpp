#include<iostream>
using namespace std;

int max(int a,int b){
    return (a>b)?a:b;
}

int knapsack(int* wt,int* p,int W,int n){
int K[n+1][W+1];
for(int i=0;i<=n;i++){
    for(int w=0;w<=W;w++){
        if(i==0||w==0){
            K[i][w]=0;
        }
        else if(wt[i-1]<=w){
            K[i][w]=max(p[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
        }
        else{
            K[i][w]=K[i-1][w];
        }
    }
}
return K[n][W];
}

int main(){
    //wt=[10,20,30];
    //p=[60,100,120];    
    int wt[100],p[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>wt[i];
        cin>>p[i];
    }
    int W;
    cin>>W;
    cout<<knapsack(wt,p,W,n);
}