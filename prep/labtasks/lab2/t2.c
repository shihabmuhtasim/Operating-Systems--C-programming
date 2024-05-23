#include <stdio.h>


//Write a C program to compute the perimeter and area of a rectangle with a height of 7 inches. and width of 5 inches.
int main(){

    int height;
    int width;
    printf("Enter height:\n");
    scanf("%d",&height);
    printf("Enter width:\n");
    scanf("%d",&width);

    printf("Perimeter %d: ", 2*(height+width));

    printf("Area %d:", height*width);

}
