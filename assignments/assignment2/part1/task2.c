//libraries of using functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

//declaration of function of finding perfect number in a range of two
int isPerfect(int n, int m);

//main function
int main(){
    //input for range of two numbers
    int n, m;
    printf("Enter two numbers: ");
    scanf("%d %d", &n, &m);
    printf("\n");
    //call function to find perfect number in a range of two
    isPerfect(n, m);
    return 0;
    }

//function to find perfect number in a range of two
int isPerfect(int n, int m){
    for(int i = n; i <= m; i++){
        int sum = 0;
        for(int j = 1; j < i; j++){
            if(i % j == 0){
                sum += j;
            }
        }
        if(sum == i){
            printf("%d \n", i);
        }
    }
}