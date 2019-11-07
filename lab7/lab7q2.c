#include<pthread.h>
#include<stdio.h>
//#include<semaphore.h>
#include<unistd.h>

#include<stdlib.h>

pthread_mutex_t x,wsem;
pthread_t tid;
int readcount;


void initialize(){
    pthread_mutex_init(&x,NULL);
    pthread_mutex_init(&wsem,NULL);
    readcount=0;
}

void * reader(void * param){
    int waittime;
    waittime=rand() % 5;
    pthread_mutex_lock(&x);
    printf("\nReader is trying to enter");
    readcount++;
    if(readcount==1){
        pthread_mutex_lock(&wsem);
    }
    printf("\nReader is inside");
    pthread_mutex_unlock(&x);
    sleep(waittime);
    pthread_mutex_lock(&x);
    readcount--;
    if(readcount==0){
        pthread_mutex_unlock(&wsem);
    }
    printf("\nReader is leaving");
    pthread_mutex_unlock(&x);
}

void * writer(void * param){
    int waittime;
    waittime=rand() % 3;
    pthread_mutex_lock(&wsem);
    printf("\nWriter has enetered");
    sleep(waittime);
    printf("\nWriter has left");
    pthread_mutex_unlock(&wsem);
    sleep(30);
}


int main(){
    int r1,w1,i;
    printf("\nenter the number of readers");
    scanf("%d",&r1);
    printf("\nenter the number of writers");
    scanf("%d",&w1);
    for(i=0;i<r1;i++){
        pthread_create(&tid,NULL,reader,NULL);
    }
    for(i=0;i<w1;i++){
        pthread_create(&tid,NULL,writer,NULL);
    }
    sleep(30);
    return 0;
}