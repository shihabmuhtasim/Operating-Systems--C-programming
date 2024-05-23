//Write a C program to sort given numbers using command line arguments.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main (int argc, char *argv[]){

    printf("Arguments %d\n", argc);

    //sort numbers
    int n=argc-1;
    int arr[n];
    for (int i=0; i<n; i++){
        arr[i]=atoi(argv[i+1]);
    }
    //print the array
    printf("Array: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    //sort the array
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    //print the sorted array
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    



}