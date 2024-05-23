#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Write a program in C to read n number of values in an array and display it in reverse order
int main(){
    int n;
    printf("Enter a number\n");
    scanf("%d", &n);
    printf("Enter arr elemets: \n");
    int arr[2500];
    int *ptr;
    ptr= arr;

    for (int i=0; i<n; i++){
        scanf(" %d", ptr);
        ptr++;
    }
    ptr--;
    for (int j=n; j>0; j--){
        printf("Val %d: %d", j,*ptr);
        ptr--;

    }    
    return 0;
}