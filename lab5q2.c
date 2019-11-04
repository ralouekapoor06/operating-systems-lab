#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc,char* arr[]){
    //now arr has all the args
    //argc has the length
    char* arr1[100];
    int h=0;
    for(int i=1;i<argc;i++){
        arr1[h]=arr[i];
        h++;
    }
    int pid=fork();
    if(pid<0){
        printf("Child not created successfully");
        printf("\n");
    }
    else if(pid==0){
        char temp[100];
        printf("I am inside the child process \n");
        for(int i=0;i<argc-1-1;i++){
            for(int j=0;j<argc-i-1-1;j++){
                if(strcmp(arr1[j],arr1[j+1])>0){           
                    strcpy(temp,arr1[j]);
                    strcpy(arr1[j],arr1[j+1]);
                    strcpy(arr1[j+1],temp);
                }
            }
        }
        printf("Now printing the sorted array \n");
        for(int i=0;i<argc-1;i++){
            printf("%s ",arr1[i]);
        }
        printf("\n");
    }
    else{
        wait(NULL);
        printf("Now printing the unsorted array \n");
        for(int i=0;i<argc-1;i++){
            printf("%s ",arr1[i]);
        }
        printf("\n");
    }

}