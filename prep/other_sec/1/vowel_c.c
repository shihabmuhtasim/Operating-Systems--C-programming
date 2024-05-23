#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

//vowel finder function

void vowel(char *a);



int main(){
    printf("Enter name : \n");
    char input[100];
    //scanf("%s",input);
    fgets(input, sizeof(input), stdin);  // Use fgets instead of scanf
    vowel(input);
      
}

void vowel(char *a){

    char arr[]={'a','e','i','o','u','A','E','I','O','U'};
    int n=strlen(a);
    for (int i=0;i<n;i++){

        //printf("Char %d is %c\n", i,a[i]);
        int flag=0;
        for(int j=0; j<10;j++){
            if(a[i]==arr[j]){
                flag=1;
                break;
            }
            }
        if (flag==1){
            printf("Vowel %c",a[i]);
        }
    }
    
}