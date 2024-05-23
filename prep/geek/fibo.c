#include <stdio.h>
#include <stdlib.h>

//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377.
int main(){

    int n=7;
    
    int f=0;
    int s=1;

    printf("%d %d", f,s);

    for (int i=0; i<n; i++){
        int num=f+s;
        f=s;
        s=num;
        printf(" %d", num);



    }

}