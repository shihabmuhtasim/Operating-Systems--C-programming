#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

//n factorial

int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int fact=1;
    if (n>=0){
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }}
    else{
        fact=-1;
    }
    printf("Factorial of %d is %d\n",n,fact);

    

}