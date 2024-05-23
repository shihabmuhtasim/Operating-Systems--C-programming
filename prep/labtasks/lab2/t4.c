#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char arr[2500];

    char *ptr;  // Declare ptr as a char *
    ptr = arr;
    for (int i=0; i<5; i++){
        scanf(" %c", ptr+i);  // Add a space before %c
    }
    
    for (int i=0; i<5; i++){
        printf("Val %d: %c\n", i, arr[i]);  // Use %d for the index and %c for the character
    } 

    return 0;
}