

//Write a C program to reverse the numbers in an array.

#include <stdio.h>
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    //reverse elements of this array so 10 comes in idx0 9 in 1 etc
    int n=10;
    for(int i=0;i<n/2;i++)
    {
        int t= arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=t;
    }
}