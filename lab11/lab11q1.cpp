#include<iostream>
using namespace std;

int matrixchainmul(int* a,int x1,int x2){
    if(x1==x2){
        return 0;
    }
    int min=999;
    int count=0;
    for(int k=x1;k<x2;k++){
        count=matrixchainmul(a,x1,k)+matrixchainmul(a,k+1,x2)+a[x1-1]*a[k]*a[x2];
    }
    if(count<min){
        min=count;
    }
    return min;
}

int main(){
    int n;
    cout<<"enter number";
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<matrixchainmul(a,1,n-1);
}