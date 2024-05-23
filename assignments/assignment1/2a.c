#include <stdio.h>


int main(){


//Task a
    int a;
    int b;
    printf("Enter first number:");
    scanf(" %d", &a);
    printf("\n");
    
    printf("Enter 2nd number:");
    scanf("%d", &b);
    if (a>b){
        printf("Subtraction result: %d\n",a-b);
    }
    else if (a<b){
        printf("Addition result: %d\n",a+b);
    }
    else{
        printf("Multiplication result: %d\n",a*b);
    }

    
}