#include<stdio.h>
#include<sys/types.h>
#include<semaphore.h>
#include<unistd.h>
#include<iostream>
using namespace std;

sem_t mutex1,mutex2;

int a,b,sum=0;

void* reader(void * args){
    sem_wait(&mutex1);
    cout<<"enter the numbers";
    cin>>a>>b;
    sem_post(&mutex2);
    
}

void* calculate(void * args){
    sem_wait(&mutex2);
    sum=a+b;
    sem_post(&mutex1);
    sem_post(&mutex2);

}

void* display(void * args){
    sem_wait(&mutex1);
    sem_wait(&mutex2);
    cout<<sum;
    sem_post(&mutex1);
}

int main(){
    sem_init(&mutex1,0,1);
    sem_init(&mutex2,0,0);
    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,reader,NULL);
    pthread_create(&t2,NULL,calculate,NULL);
    pthread_create(&t3,NULL,display,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
}