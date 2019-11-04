#include<stdio.h>
#include<stdlib.h>

int n,mutex=1,empty=3,full=0,val=1,num_prod=0,num_consum=0;

int main(){
    int signal(int c);
    int wait(int c);
    void producer();
    void consumer();
    while(val){
        printf("Enter 1. Producer 2.Consumer 3.Breaking out");
        scanf("%d",&n);
        switch(n){
            case 1:
                if(mutex==1 && empty!=0){
                    producer();
                }
                else{
                    printf("The bag is full");
                }
                break;
            case 2:
                if(mutex==1 && full!=0){
                    consumer();
                }
                else{
                    printf("The bag is empty");
                }
                break;
            case 3:
                val=0;
                break;
        }
    }
}

int signal(int c){
    return ++c;
}

int wait(int c){
    return --c;
}

void producer(){
    mutex=wait(mutex);
    empty=wait(empty);
    full=signal(full);
    printf("Producer has produced item");
    printf("%d",num_prod);
    num_prod=num_prod+1;
    if(num_prod==3){
        num_prod=0;
    }
    mutex=signal(mutex);
}

void consumer(){
    mutex=wait(mutex);
    empty=signal(empty);
    full=wait(full);
    printf("Consumer has consumed an item");
    printf("%d",num_consum);
    num_consum=num_consum+1;
    if(num_consum==3){
        num_consum=0;
    }
    mutex=signal(mutex);
}



