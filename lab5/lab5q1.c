#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
    int pid=fork();
    if(pid<0){
        printf("The child is not created properly \n");
    }
    else if(pid==0){
        printf("We are in child process \n");
        printf("The child process id is ");
        printf("%d  \n",getpid());
        printf("The Parent process id is ");
        printf("%d \n",getppid());
    }
    else{
        printf("Successful creation of child process \n");
    }
}
