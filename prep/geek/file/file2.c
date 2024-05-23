#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
    FILE *f1, *f2;
    f1=fopen("f11.txt","r");
    f2=fopen("f12.txt","r");
    //compare two files words by words
    char s1[100], s2[100];
    while(fscanf(f1,"%s",s1)!=EOF){
        fscanf(f2,"%s",s2);
        printf("s1:%s   s2:%s\n",s1,s2);
        if(strcmp(s1,s2)!=0){
            printf("Files are not same\n");
            return 0;
        }
    }
}