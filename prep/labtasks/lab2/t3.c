#include <stdio.h>

//Write a C program to compute the perimeter and area of a circle with a given radius.

int main(){

    int r;
    int pi=3.1415;
    
    printf("Enter radius:\n");
    scanf("%d",&r);

    printf("Perimeter %d: ", 2*r*pi);
    //Area of a circle = πr^2
    printf("Area %d: ", pi*r*r);
    

}
