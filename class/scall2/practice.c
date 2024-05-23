#include <stdio.h>
#include <stdlib.h>


// void swap(int *a, int *b){
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
// int main(){
//task1 -find vowel
// char i;
// scanf("%c",&i);

// printf("Input taken: %c",i);

// char araa[]={'a','e','i','u','o'};
// int x;
// int flag=0;
// for (x=0;x<5;x++){
//     if (araa[x]==i){
//         flag=1;
//         break;
//     }
// }
// printf("Flag %d",flag);

//i+=2 to inc by 2 in for loop

// int a=5;
// int b=6;
// swap(&a,&b);

// printf("%d",a);

// }










//unsuccessful
// int main(int argc, char *argv[]) {
//     int i, j;
//     char *temp;

//     for (i = 1; i < argc; i++) {
//         for (j = i; j < argc; j++) {
//             if (atoi(argv[j]) < atoi(argv[i])) {
//                 temp = argv[j];
//                 argv[j] = argv[i];
//                 argv[i] = temp;
//             }
//         }
//     }

//     for (i = 1; i < argc; i++) {
//         printf("%d ", atoi(argv[i]));
//     }

//     return 0;
// }