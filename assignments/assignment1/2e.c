#include <stdio.h>


int main(){


    //Task5
printf("%s","Enter string: ");
char str[100];
scanf("%s", str);

char *ptr=str;


char *ptr_1=str;

int i=0;

while (*ptr != ' ' && *ptr!='\0'){
    i+=1; 
    ptr++;
}
ptr-=1;

int flag=0;
int x=0;
for (x=0;x<i;x++){

    



    if (*ptr_1!=*ptr){
        // printf("  Unmatched from right: %c",*ptr_1);
        // printf("  Unmatched from left: %c",*ptr);

        flag=1;
        break;
    }
    
    ptr_1+=1;
    ptr-=1;
    


    }
if (flag==0){
    printf("OUTPUT: %s","Palindrome");
}
else{
    printf("OUTPUT: %s","Not Palindrome");
}


}