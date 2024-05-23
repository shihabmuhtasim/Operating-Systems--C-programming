#include <stdio.h>


int main(){

    //using if else conditions- first take input in a, then if a =5 then print a else dont

    int a;
    scanf("%d", &a);

    switch (a){
    case 5:
        printf("%d Five\n",a);
        break;
    case 7:
        printf("%d Fseven\n",a);
        break;
    default:
        printf("%d none\n",a);
        

    }

    Task a
    int a;
    int b;
    printf("Enter first number:");
    scanf(" %d", &a);
    printf("\n");
    
    printf("Enter 2nd number:");
    scanf("%d", &b);
    if (a>b){
        printf("Subtraction result: %d\n",a-b);
    }
    else if (a<b){
        printf("Addition result: %d\n",a+b);
    }
    else{
        printf("Multiplication result: %d\n",a*b);
    }

    

    //task b
    FILE *f;
    f= fopen("taskb.txt","r");
    char str[1000];
    fgets(str,255,f);
    printf("The text file contains:%s\n",str);

    
    f=fopen("taskb-w.txt","w");
    printf("Written in output file:");
    int i;
    i=0;
    while (str[i]!='\0'){
        if(str[i]!=' '){
            printf("%c",str[i]);
            fprintf(f,"%c",str[i]);
            i++;
        }
        else{
            printf("%c",str[i]);
           fprintf(f,"%c",str[i]);
           i++;
           while (str[i]==' '){
                NULL;
                i++;
           }
        }
        
    }


    TASKc
    
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
        if ('!'<=str[i] && str[i]<='/'){
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
        if (check[0]==0){
            printf("OUTPUT: %s","Lower character missing, ");
        }
        if (check[1]==0){
            printf("OUTPUT: %s","Upper character missing, ");
        }
        if (check[2]==0){
            printf("OUTPUT: %s","Digit missing, ");
        }
        if (check[3]==0){
            printf("OUTPUT: %s","Special character missing");
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
    else{
       printf("OUTPUT: %s","OK"); 
    } 


TASK D
printf("%s","Enter email address: ");
char str[100];

scanf("%s", &str);
int i;
i=0;
int flag=0;
while (str[i] != ' ' && str[i] != '\0') {
    if (str[i]=='@'){
        if (str[i+1]=='k' && str[i+2]=='a' && str[i+3]=='a' && str[i+4]=='j' && str[i+5]=='.'){
            flag=0;
        }
        else if (str[i+1]=='s' && str[i+2]=='h' && str[i+3]=='e' && str[i+4]=='b' && str[i+5]=='a' ){
            flag=1;
        }
        
    }
    


i++;

}
if (flag==0){
    printf("Output: %s\n","Email address is outdated");
}
else {
    printf("Output: %s\n","Email address is okay");
}

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
        printf("  Unmatched from right: %c",*ptr_1);
        printf("  Unmatched from left: %c",*ptr);

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


    




