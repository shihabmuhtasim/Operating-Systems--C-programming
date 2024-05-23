#include<stdio.h>
int main(int argc, char* argv[]){
    printf("Program-1 arguments passed: %d", argc);
    for(int i=0; i<argc; i++){
    printf("%s", argv[i]);
}
}

//gcc pr1.c -o pr1 && ./pr1 1 2 3 4