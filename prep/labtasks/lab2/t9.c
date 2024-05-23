#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Write a C program to concatenate two strings given by the user.


int main(){

    printf("Enter string 1:");
    char s1[100];
    scanf("%s", s1);

    printf("Enter string 2:");
    char s2[100];
    scanf("%s", s2);

    //concatenate s2 to s1
    strcat(s1, s2);
    printf("Concatenated string: %s", s1); 


}





