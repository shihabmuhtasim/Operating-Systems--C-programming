//command line argument

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int arr[argc-1];
    for(int i = 1; i < argc; i++) {
        
        arr[i-1] = atoi(argv[i]);
        
    }
    
    // Check if numbers in array are odd or even

    for(int i=0; i<argc-1; i++){
        if (arr[i]%2!=0){
            printf("Odd number: %d\n", arr[i]);
        }
        else{
            printf("Even number: %d\n", arr[i]);
        }
    }


}