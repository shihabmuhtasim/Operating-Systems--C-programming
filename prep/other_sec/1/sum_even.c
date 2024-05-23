#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Write programme to take a value as input and print the sub of even numbers in it

int SumofEven(char * a);
int main(){

    printf("Enter val:");
    char id[100];
    scanf("%s",id);
    SumofEven(id);
    
}

int SumofEven(char *a){
    
    int sum=0;

    int n= strlen(a);
    for (int i=0; i<n; i++){
        int v= a[i]-'0';
        if (v%2==0){
            sum+=v;
        }
        
        
    }
    printf("SUM %d", sum);

}



