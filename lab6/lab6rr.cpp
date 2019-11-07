#include<iostream>
#include<queue>
using namespace std;

int main(){
	queue <int> q;
	int n,remain,time=0,ptime=0,quantum=0,count,flag,totall[100],k=0;
	float wt=0,tat=0;
	totall[k++]=0;
	cout<<"enter the number of process";
	cin>>n;
	cout<<"enter the arrival time and burst time";
	int at[n],bt[n],rt[n];
	for(int i=0;i<n;i++){
		cin>>at[i];
		cin>>bt[i];
	}
	
	cout<<"enter time quantum";
	cin>>quantum;
	for(int i=0;i<n;i++){
		rt[i]=bt[i];
	}
	for(int i=0;i<n;i++){
		if(at[i]==0){
			count=i;
			break;
		}
	}
	remain=n;
	while(remain>0){
		if(!q.empty()){
			count=q.front();
			q.pop();	
		}
		if(rt[count]<=quantum && rt[count]>=0){
			time+=rt[count];
			rt[count]=0;
			flag=1;
		//cout<<count<<" ";
	}
	else if(rt[count]>0){
		rt[count]-=quantum;
		time+=quantum;
		cout<<count+1<<"      |";
		totall[k++]=time;
	}
	if(rt[count]==0 && flag==1){
		remain--;
		wt+=time-at[count]-bt[count];
		tat+=time-at[count];
		cout<<count+1<<"      |";
		totall[k++]=time;
		flag=0;
	}
	for(int i=ptime;i<=time;i++){
		for(int j=0;j<n;j++){
			if(j==count || rt[j]<=0){
				continue;
			}
			if(at[j]==i){
				q.push(j);
			}
		}
	}
	if(rt[count]>0){
		q.push(count);
	}
	ptime=time;
}	
cout<<"\n";
for(int y=0;y<k;y++){
	cout<<totall[y]<<"         |";
}
cout<<tat/n;
cout<<wt/n;

return 0;
}


