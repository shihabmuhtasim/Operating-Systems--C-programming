#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Write a C Program to Swap Values of Two Variables.

void swap(char *a, char *b);
int main(){

    char a='H';
    char b='L';
    swap(&a,&b);

    printf("a has %c\n", a);
    printf("b has %c\n", b);

  

}

void swap(char *a, char *b){
    char temp;

    temp=*a;
    *a=*b;
    *b=temp;

    return ;



}