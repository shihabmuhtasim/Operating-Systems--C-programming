#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Write a C program to convert a given integer (in seconds) to hours, minutes and seconds.
int main(){
    
    float seconds;
    printf("Enter seconds: ");
    scanf("%f", &seconds);
    int hours = seconds / 3600;
    printf("Hour %d", hours);
    int min;
    min= (seconds- (hours*3600))/60;
    printf("Min:%d", min);
    int sec;
    sec= (seconds-(hours*3600)-(min*60));
    printf("Sec:%d", sec);

}