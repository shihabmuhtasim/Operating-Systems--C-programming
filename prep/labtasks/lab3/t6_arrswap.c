//Write a C program to swap two numbers in an array using function call by reference.

#include <stdio.h>

void arrswap( int *ptr);
int main(){

    int arr[]={1,2};

    arrswap (arr);
    //print the swapped values
    printf("After swapping: %d %d\n",arr[0],arr[1]);



}
void arrswap( int *ptr){
    //print ptr
    printf("ptr: %p\n",ptr);
    //print what is inside ptr
    printf("Before swapping: %d %d\n",ptr[0],ptr[1]);
    //swap the values
    int temp=ptr[0];
    ptr[0]=ptr[1];
    ptr[1]=temp;
    //return the array loaction
    return ;



}