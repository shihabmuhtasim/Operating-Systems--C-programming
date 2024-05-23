#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Write programme to take a value as input and print the sub of even numbers in it

int SumofEven(int  a);
int main(){

    printf("Enter val:");
    int id;
    scanf("%d",&id);
    SumofEven(id);
    
}

int SumofEven(int a){
    int  n;
    //find the number of digits in int a in n
    n=0;
    int temp=a;
    while (temp>0){
        temp=temp/10;
        n++;
    }

    printf("N: %d\n", n);
    int sum=0;
    //disect each digit seperately of int a
    int x=1;
    for (int i=0; i<n; i++){
        x*=10;}

    printf("X: %d\n", x);

    for (int i=0; i<n; i++){
        int v= a/x;
        printf("V: %d\n", v);
        if (v%2==0){
            sum+=v;
        }
        a=a%x;
        printf("A: %d\n", a);
        x=x/10;
        
    }

    printf("SUM %d", sum);

}
    





