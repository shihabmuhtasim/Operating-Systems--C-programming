#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

//first c multiples of n in file

int main(){
    int n=5;
    int c=3;

    FILE *fp;
    fp= fopen("multiples.txt","w");
    fprintf(fp,"START:\n");
    
    for (int i=0; i<c; i++){
        fprintf(fp,"Multiple no %d is %d \n", i+1, n*i);
    }

}

