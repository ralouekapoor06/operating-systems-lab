#include<stdio.h>

int parent[9],min,mincost=0,n,x,ne=1,a1,b1,u,v,a[100][100],z;

int find(int i){
    while(parent[i])
    i=parent[i];
    return i;
}

int uni(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}


int main(){
    printf("Enter the number of vertices");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&z);
            a[i][j]=z;
            if(a[i][j]==0){
                a[i][j]=999;
            }
        }
    }

    while(ne<n){
        for(int i=1,min=999;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]<min){
                    min=a[i][j];
                    a1=u=i;
                    b1=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v)){
            printf("Min edge are ");
            printf("%d",a1);
            printf("%d",b1);
            printf("Cost is ");
            printf("%d",min);
            printf("\n");
            mincost+=min;
            ne++;
        }
        a[a1][b1]=a[a1][b1]=999;
    }
    printf("%d",mincost);
}