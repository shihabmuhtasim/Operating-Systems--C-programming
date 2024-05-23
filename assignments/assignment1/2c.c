#include <stdio.h>


int main(){


 //TASKc
    printf("%s","Enter password: ");
    int check[4]={0};
    char str[100];
    
    scanf("%s",str);

    int i;
    i=0;
    

    
    while (str[i] != ' ' && str[i] != '\0') {
        
        if ('a'<=str[i] && str[i]<='z'){
            check[0]+=1; 
            //lowercase 0
        }
        if ('A'<=str[i] && str[i]<='Z'){
            check[1]+=1;
            //uppercase 1
        }
        if ('0'<=str[i] && str[i]<='9'){
            check[2]+=1;
            //digits 2
        }
        if (('!'<=str[i] && str[i]<='/') || (':'<=str[i] && str[i]<='@') || ('['<=str[i] && str[i]<='_')){
            check[3]+=1;
            //special 3
        }
        
        i++;

    }
    printf("Lowercase: %d\n", check[0]);
    printf("Uppercase: %d\n", check[1]);
    printf("Digits: %d\n", check[2]);
    printf("Special: %d\n", check[3]);

    int counter;
    counter=0;

    for (i=0;i<4;i++){
        if (check[i]==0){
            counter+=1;
        }
    }
    if (counter>1){
        printf("%s","Output: ");
        if (check[0]==0){
            printf(" %s","Lower character missing, ");
        }
        if (check[1]==0){
            printf("%s","Upper character missing, ");
        }
        if (check[2]==0){
            printf("%s","Digit missing, ");
        }
        if (check[3]==0){
            printf("%s","Special character missing");
        }
        
        
    }
    if (counter==1){ 
        if (check[0]==0){
            printf("OUTPUT: %s","Lower character missing");
        }
        if (check[1]==0){
            printf("OUTPUT: %s","Upper character missing");
        }
        if (check[2]==0){
            printf("OUTPUT: %s","Digit missing");
        }
        if (check[3]==0){
            printf("OUTPUT: %s","Special character missing");
        }    
        
    }
    else if (counter==0){
       printf("OUTPUT: %s","OK"); 
    } 


    
}