//Cntrl +I- chat w copilot

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

int main(int argc, char *argv[]) {
    int arr[argc-1];
    for(int i = 1; i < argc; i++) {
        
        arr[i-1] = atoi(argv[i]);
        //printf("Argument: %d\n", arr[i-1]);
    }
    
    // Sort the array
    for(int i = 0; i < argc; i++) {
        for(int j = i + 1; j < argc; j++) {
            if(arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
        }
        
    }

    printf("Sorted array in decending order: ");
    //print after sorting
    for(int i = 0; i < argc-1; i++) {
        
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}