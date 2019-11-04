#include<iostream>
using namespace std;



int main(){
    int n,tw;
    int profit;
    int weight;
    int p[100];
    int w[100];
    int profitden[100],temp;
    cout<<"enter number of items";
    cin>>n;
    cout<<"enter the profit and weights";
    for(int i=0;i<n;i++){
        cin>>profit;
        cin>>weight;
        int pd=profit/weight;
        p[i]=profit;
        w[i]=weight;
        profitden[i]=pd;
    }
    cin>>tw;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(profitden[j]<profitden[j+1]){

                temp=profitden[j];
                profitden[j]=profitden[j+1];
                profitden[j+1]=temp;

                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;

                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
        }
    }
    }
    for(int i=0;i<n;i++){
        cout<<w[i]<<" "<<p[i]<<" "<<profitden[i]<<"\n" ;
    }
    int tot_w=0,tot_prof=0;
    int j=0;
    while(tot_w<=tw){
        tot_w=tot_w+w[j];
        tot_prof=tot_prof+p[j];
        j++;
    }
    tot_prof=tot_prof-p[--j];
    cout<<"Total profit is";
    cout<<tot_prof;
}